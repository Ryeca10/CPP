#include <iostream>
using namespace std;

int main()
{

int N10 = 2304;
int BASE = 8;
int N8 = 0 ;
int K = 1 ;
int R =   N10 % BASE ;
int Q = (N10 - R) / BASE;
cout << N10 << " " << Q << " " << N8 << " " << R << " " << K << " " << BASE << endl;
N8 = N8 + R*K;
cout << N10 << " " << Q << " " << N8 << " " << R << " " << K << " " << BASE << endl;
N10 = Q;
cout << N10 << " " << Q << " " << N8 << " " << R << " " << K << " " << BASE << endl;
K = K*10 ;
cout << N10 << " " << Q << " " << N8 << " " << R << " " << K << " " << BASE << endl;
R =   N10 % BASE ;
cout << N10 << " " << Q << " " << N8 << " " << R << " " << K << " " << BASE << endl;
Q = (N10 - R) /BASE;
cout << N10 << " " << Q << " " << N8 << " " << R << " " << K << " " << BASE << endl;
N8 = N8 + R*K;
cout << N10 << " " << Q << " " << N8 << " " << R << " " << K << " " << BASE << endl;
N10 = Q;
cout << N10 << " " << Q << " " << N8 << " " << R << " " << K << " " << BASE << endl;
K = K * 10;
cout << N10 << " " << Q << " " << N8 << " " << R << " " << K << " " << BASE << endl;
R =   N10 % BASE ;
cout << N10 << " " << Q << " " << N8 << " " << R << " " << K << " " << BASE << endl;
Q = (N10 - R) /BASE;
cout << N10 << " " << Q << " " << N8 << " " << R << " " << K << " " << BASE << endl;
N8 = N8 + R*K;
cout << N10 << " " << Q << " " << N8 << " " << R << " " << K << " " << BASE << endl;
N10 = Q;
cout << N10 << " " << Q << " " << N8 << " " << R << " " << K << " " << BASE << endl;
K = K*10;
cout << N10 << " " << Q << " " << N8 << " " << R << " " << K << " " << BASE << endl;
R =   N10 % BASE ;
cout << N10 << " " << Q << " " << N8 << " " << R << " " << K << " " << BASE << endl;
Q= (N10 - R) / BASE;
cout << N10 << " " << Q << " " << N8 << " " << R << " " << K << " " << BASE << endl;
N8= N8 + R*K;
cout << N10 << " " << Q << " " << N8 << " " << R << " " << K << " " << BASE << endl;
N10 = Q;
cout << N10 << " " << Q << " " << N8 << " " << R << " " << K << " " << BASE << endl;
K = K * 10;

cout << N10 << " " << Q << " " << N8 << " " << R << " " << K << " " << BASE << endl;

return 0;
}