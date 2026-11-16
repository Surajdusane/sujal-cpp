#include <iostream>
#include <string>
using namespace std;
struct Appointment {
int start, end;
string name;
Appointment* prev;
Appointment* next;
};
class Schedule {
private:
Appointment* head;
int toMinutes(int h, int m) {
return h * 60 + m;
}
void showTime(int t) {
cout << (t / 60) << ":" << (t % 60 < 10 ? "0" : "") << t % 60;
}
bool overlap(int s, int e) {
for (Appointment* p = head; p; p = p->next) {
if (!(e <= p->start || s >= p->end)) {
return true;
}
if (p->start > e) {
break;
}
}
return false;
}
public:
Schedule() : head(nullptr) { }
void bookAppointment() {
int sh, sm, eh, em;
string name;
cout << "Enter name: ";
cin >> name;
cout << "Enter start time (hh mm): ";
cin >> sh >> sm;
cout << "Enter end time (hh mm): ";
cin >> eh >> em;
int s = toMinutes(sh, sm);
int e = toMinutes(eh, em);
if (s >= e || s < 540 || e > 1020) {
cout << "Invalid time! Working hours: 9:00 - 17:00.\n";
return;
}
if (e - s < 30) {
cout << "Minimum slot is 30 minutes!\n";
return;
}
if (overlap(s, e)) {
cout << "Slot not free!\n";
return;
}
Appointment* n = new Appointment{s, e, name, nullptr, nullptr};
if (!head) {
head = n;
return;
}
Appointment* p = head;
while (p->next && p->next->start < s) {
p = p->next;
}
n->next = p->next;
if (p->next) {
p->next->prev = n;
}
n->prev = p;
p->next = n;
cout << "Appointment booked!\n";
}
void displayAppointments() {
if (!head) {
cout << "No appointments scheduled.\n";
return;
}
cout << "\nAppointments:\n";
for (Appointment* p = head; p; p = p->next) {
showTime(p->start);
cout << " - ";
showTime(p->end);
cout << " : " << p->name << "\n";
}
}
void displayFreeSlots() {
cout << "\nFree 30-Minute Slots:\n";
if (!head) {
cout << "9:00 - 17:00\n";
return;
}
int prevEnd = 540;
for (Appointment* p = head; p; p = p->next) {
if (p->start > prevEnd) {
showTime(prevEnd);
cout << " - ";
showTime(p->start);
cout << "\n";
}
prevEnd = p->end;
}
if (prevEnd < 1020) {
showTime(prevEnd);
cout << " - 17:00\n";
}
}
void cancelAppointment() {
int h, m;
cout << "Enter start time (hh mm): ";
cin >> h >> m;
int t = toMinutes(h, m);
Appointment* p = head;
while (p && p->start != t) {
p = p->next;
}
if (!p) {
cout << "Appointment not found!\n";
return;
}
if (p->prev) {
p->prev->next = p->next;
} else {
head = p->next;
}
if (p->next) {
p->next->prev = p->prev;
}
delete p;
cout << "Appointment cancelled successfully.\n";
}
void sortByData() {
if (!head) return;
for (Appointment* i = head; i && i->next; i = i->next) {
for (Appointment* j = head; j && j->next; j = j->next) {
if (j->start > j->next->start) {
swap(j->start, j->next->start);
swap(j->end, j->next->end);
swap(j->name, j->next->name);
}
}
}
cout << "Appointments sorted by data.\n";
displayAppointments();
}
void sortByPointer() {
if (!head || !head->next) return;
Appointment* sorted = nullptr;
while (head) {
Appointment* curr = head;
head = head->next;
curr->prev = curr->next = nullptr;
if (!sorted || curr->start < sorted->start) {
curr->next = sorted;
if (sorted) sorted->prev = curr;
sorted = curr;
} else {
Appointment* p = sorted;
while (p->next && p->next->start < curr->start) {
p = p->next;
}
curr->next = p->next;
if (p->next) p->next->prev = curr;
p->next = curr;
curr->prev = p;
}
}
head = sorted;
cout << "Appointments sorted by pointer.\n";
displayAppointments();
}
};
int main() {
Schedule s;
int choice;
do {
cout << "\n===== APPOINTMENT MANAGEMENT =====\n";
cout << "1. Book Appointment\n";
cout << "2. Display Appointments\n";
cout << "3. Display Free Slots\n";
cout << "4. Cancel Appointment\n";
cout << "5. Sort by Data\n";
cout << "6. Sort by Pointer\n";
cout << "7. Exit\n";
cout << "Enter choice: ";
cin >> choice;
switch (choice) {
case 1: s.bookAppointment(); break;
case 2: s.displayAppointments(); break;
case 3: s.displayFreeSlots(); break;
case 4: s.cancelAppointment(); break;
case 5: s.sortByData(); break;
case 6: s.sortByPointer(); break;
case 7: cout << "Exiting program...\n"; break;
default: cout << "Invalid choice!\n";
}
} while (choice != 7);
return 0;
}
/*
hp@hp-HP-Pro-Tower-280-G9-PCI-Desktop-PC:~$ ./a.out
===== APPOINTMENT MANAGEMENT =====
1. Book Appointment
2. Display Appointments
3. Display Free Slots
4. Cancel Appointment
5. Sort by Data
6. Sort by Pointer
7. Exit
Enter choice: 1
Enter name: Riya
Enter start time (hh mm): 9 30
Enter end time (hh mm): 10 00
Appointment booked!
===== APPOINTMENT MANAGEMENT =====
Enter choice: 1
Enter name: John
Enter start time (hh mm): 10 30
Enter end time (hh mm): 11 30
Appointment booked!
===== APPOINTMENT MANAGEMENT =====
Enter choice: 2
Appointments:
9:30 - 10:00 : Riya
10:30 - 11:30 : John
===== APPOINTMENT MANAGEMENT =====
Enter choice: 3
Free 30-Minute Slots:
9:00 - 9:30
10:00 - 10:30
11:30 - 17:00
===== APPOINTMENT MANAGEMENT =====
Enter choice: 4
Enter start time (hh mm): 9 30
Appointment cancelled successfully.
===== APPOINTMENT MANAGEMENT =====
Enter choice: 2
Appointments:
10:30 - 11:30 : John
===== APPOINTMENT MANAGEMENT =====
Enter choice: 7
Exiting program...
*/