/*
ID: zengshu1
PROG: gift1
LANG: C++
*/

/*
题意：有n个人，先分别给出他们的名字，然后每个人都拥有x元，他要把这x元分给m个人，每个人分x/m(向下取整)元
	问最终每个人剩下的钱比原来增加了多少？
*/
#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <map>
using namespace std;

int main() {

	freopen("gift1.in", "r", stdin);
	freopen("gift1.out", "w", stdout);
	int n;
	scanf("%d", &n);
	map<string, int>mp;
	string name[20];
	for (int i = 0; i < n; ++i) {
		cin >> name[i];
		mp[name[i]] = i;
	}
	int ori[20], now[20] = {0};
	for (int i = 0; i < n; ++i) {
		string str;
		int own, m;
		cin >> str >> own >> m;
		ori[mp[str]] = own;
		for (int j = 0; j < m; ++j) {
			string to;
			cin >> to;	
			now[mp[to]] += own/m;
		}
		if (m) now[mp[str]] += own%m;
	}
	for (int i = 0; i < n; ++i)
		cout << name[i] << " " << now[i] - ori[i] << "\n";
    return 0;
}


/*
   data inputs:
------- test 1 ----
10

mitnik

Poulsen

Tanner

Stallman

Ritchie

Baran

Spafford

Farmer

Venema

Linus

mitnik

300 3

Poulsen

Tanner

Baran

Poulsen

1000 1

Tanner

Spafford

2000 9

mitnik

Poulsen

Tanner

Stallman

Ritchie

Baran

Farmer

Venema

Linus

Tanner

1234 1

Poulsen

Stallman

536 3

Farmer

Venema

Linus

Ritchie

2000 1

mitnik

Baran

79 2

Tanner

Farmer

Farmer

0 0

Venema

12 9

mitnik

Poulsen

Tanner

Stallman

Ritchie

Baran

Spafford

Farmer

Linus

Linus

1000 1

mitnik

------- test 2 ----
5

dave

laura

owen

vick

amr

dave

200 3

laura

owen

vick

owen

500 1

dave

amr

150 2

vick

owen

laura

0 2

amr

vick

vick

0 0

------- test 3 ----
2

john

lennon

lennon

0 0

john

0 0

------- test 4 ----
10

Alex

Bob

Catherine

Dave

Ebert

Francis

Godot

Harris

Iliya

Jimbo

Alex

2000 9

Bob

Catherine

Dave

Ebert

Francis

Godot

Harris

Iliya

Jimbo

Bob

2000 9

Alex

Catherine

Dave

Ebert

Francis

Godot

Harris

Iliya

Jimbo

Catherine

2000 9

Alex

Bob

Dave

Ebert

Francis

Godot

Harris

Iliya

Jimbo

Dave

2000 9

Alex

Bob

Catherine

Ebert

Francis

Godot

Harris

Iliya

Jimbo

Ebert

2000 9

Alex

Bob

Catherine

Dave

Francis

Godot

Harris

Iliya

Jimbo

Francis

2000 9

Alex

Bob

Catherine

Dave

Ebert

Godot

Harris

Iliya

Jimbo

Godot

2000 9

Alex

Bob

Catherine

Dave

Ebert

Francis

Harris

Iliya

Jimbo

Harris

2000 9

Alex

Bob

Catherine

Dave

Ebert

Francis

Godot

Iliya

Jimbo

Iliya

2000 9

Alex

Bob

Catherine

Dave

Ebert

Francis

Godot

Harris

Jimbo

Jimbo

2000 9

Alex

Bob

Catherine

Dave

Ebert

Francis

Godot

Harris

Iliya

------- test 5 ----
4

these

names

are

dumb

dumb

534 3

these

dumb

are

are

351 1

names

these

509 2

dumb

names

names

278 1

dumb

------- test 6 ----
2

someguy

someotherguy

someotherguy

1500 1

someguy

someguy

500 1

someotherguy

------- test 7 ----
8

a

b

c

d

e

f

g

h

c

500 4

a

b

d

h

f

290 3

a

b

c

a

489 7

b

c

d

e

f

h

g

g

0 0

e

1789 2

f

h

d

2000 5

a

b

h

f

e

b

192 5

a

c

h

g

d

h

0 2

a

b

------- test 8 ----
10

paul

stan

mark

doug

fred

bill

hank

rich

mike

john

paul

0 0

john

300 2

paul

stan

stan

1000 1

paul

mark

2000 3

paul

stan

doug

doug

510 2

paul

stan

fred

1560 2

paul

stan

bill

178 2

paul

stan

hank

97 2

paul

stan

rich

1999 2

paul

stan

mike

1531 2

paul

stan

------- test 9 ----
10

paul

stan

mark

doug

fred

bill

hank

rich

mike

john

paul

1693 6

stan

mark

doug

fred

bill

hank

john

1843 3

hank

mike

paul

stan

1346 9

paul

mark

fred

bill

doug

hank

rich

mike

john

mark

1657 1

paul

doug

1256 9

paul

stan

bill

mark

fred

rich

hank

mike

john

fred

1250 6

paul

stan

bill

rich

john

mike

bill

1999 2

john

mike

hank

2000 8

stan

mark

doug

fred

rich

bill

mike

john

rich

1999 3

paul

bill

hank

mike

1999 5

hank

bill

mark

rich

john

*/
