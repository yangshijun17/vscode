#include <iostream>

using namespace std;
typedef long long ll;
ll get_dep(ll x)
{
    if(x==1) return 1;
    else
        return x+get_dep(x-1);
}

int main()
{
    cout << get_dep(43429) << endl;///×î´óÎª43429
    return 0;
}
