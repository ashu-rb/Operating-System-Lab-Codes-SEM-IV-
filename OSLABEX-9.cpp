//FIRST FIT
#include<iostream>
using namespace std;
int main() {
int bsize[10], psize[10], bno, pno, flags[10], allocation[10], i, j;
for (i = 0; i < 10; i++) {
flags[i] = 0;
allocation[i] = -1;
}
cout << "Enter no. of blocks: ";
cin >> bno;
cout << "\nEnter size of each block: ";
for (i = 0; i < bno; i++)
cin >> bsize[i];
cout << "\nEnter no. of processes: ";
cin >> pno;
cout << "\nEnter size of each process: ";
for (i = 0; i < pno; i++)
cin >> psize[i];
for (i = 0; i < pno; i++)
for (j = 0; j < bno; j++)
if (flags[j] == 0 && bsize[j] >= psize[i]) {
allocation[j] = i;
flags[j] = 1;
break;
}
cout << "\nBlock no.\tsize\t\tprocess no.\t\tsize";
for (i = 0; i < bno; i++) {
cout << "\n" << i + 1 << "\t\t" << bsize[i] << "\t\t";
if (flags[i] == 1) {
cout << allocation[i] + 1 << "\t\t\t" << psize[allocation[i]];
}
else {
cout << "Not allocated";
}
}
return 0;
}

//BEST FIT
#include<iostream>
using namespace std;
int main() {
int fragment[20], b[20], p[20], i, j, nb, np, temp, lowest = 9999;
static int barray[20], parray[20];
cout << "\nEnter the number of blocks:";
cin >> nb;
cout << "\nEnter the size of the blocks:-\n";
for (i = 1; i <= nb; i++) {
cin >> b[i];
}
cout << "Enter the number of processes:";
cin >> np;
cout << "\nEnter the size of the processes :-\n";
for (i = 1; i <= np; i++) {
cin >> p[i];
}
for (i = 1; i <= np; i++) {
for (j = 1; j <= nb; j++) {
if (barray[j] != 1) {
temp = b[j] - p[i];
if (temp >= 0)
if (lowest > temp) {
parray[i] = j;
lowest = temp;
}
}
}
fragment[i] = lowest;
barray[parray[i]] = 1;
lowest = 10000;
}
cout << "\nProcess_no\tProcess_size\tBlock_no\tBlock_size\tFragment";
for (i = 1; i <= np && parray[i] != 0; i++)
cout << "\n" << i << "\t\t" << p[i] << "\t\t" << parray[i] << "\t\t" << b[parray[i]] << "\t\t" << fragment[i];
return 0;
}
//WORST FIT
#include<iostream>
#include<algorithm>
using namespace std;
struct node {
int memsize;
int allocp = -1;
int pos;
int allocSize;
} m[200];
bool posSort(node a, node b) {
return a.pos < b.pos;
}
bool memSort(node a, node b) {
return a.memsize > b.memsize;
}
int main() {
int nm, np, i, j, p[200];
cout << "Enter number of blocks: \n";
cin >> nm;
cout << "Enter block size: \n";
for (i = 0; i < nm; i++) {
cin >> m[i].memsize;
m[i].pos = i;
}
cout << "Enter number of processes: \n";
cin >> np;
cout << "Enter process size: \n";
for (i = 0; i < np; i++) {
cin >> p[i];
}
cout << "\n\n";
sort(m, m + nm, memSort);
int globalFlag = 0;
for (i = 0; i < np; i++) {
int flag = 0;
for (j = 0; j < nm; j++) {
if (p[i] <= m[j].memsize && m[j].allocp == -1) {
m[j].allocp = i;
m[j].allocSize = p[i];
flag = 1;
break;
}
}
if (flag == 0) {
cout << "Unallocated Process P" << i + 1 << "\n";
globalFlag = 1;
}
}
sort(m, m + nm, posSort);
cout << "\n";
int intFrag = 0, extFrag = 0;
cout << "Memory\t\t";
for (i = 0; i < nm; i++) {
cout << m[i].memsize << "\t";
}
cout << "\n";
cout << "P. Alloc.\t";
for (i = 0; i < nm; i++) {
if (m[i].allocp != -1) {
cout << "P" << m[i].allocp + 1 << "\t";
} else {
cout << "Empty\t";
}
}
cout << "\n";
cout << "Int. Frag.\t";
for (i = 0; i < nm; i++) {
if (m[i].allocp != -1) {
cout << m[i].memsize - m[i].allocSize << "\t";
intFrag += m[i].memsize - m[i].allocSize;
} else {
extFrag += m[i].memsize;
cout << "Empty\t";
}
}
cout << "\n";
cout << "\n";
if (globalFlag == 1)
cout << "Total External Fragmentation: " << extFrag << "\n";
else {
cout << "Available Memory: " << extFrag << "\n";
}
cout << "Total Internal Fragmentation: " << intFrag << "\n";
return 0;}