/* CCF201409-2 ��ͼ */

#include <iostream>
#include <cstring>

using namespace std;

const int N = 100;

bool flag[N+1][N+1];

int main()
{
    int n, x1, y1, x2, y2, sum=0;

    // ������ʼ��
    memset(flag, false, sizeof(flag));

    // �������ݣ����㴦��
    cin >> n;
    for(int i=1; i<=n; i++) {
        // ��������
        cin >> x1 >> y1 >> x2 >> y2;

        // �ۼ����
        sum += (x2 - x1) * (y2 - y1);

        // ��Ǻ�ȥ���ص�����
        for(int i=x1; i<x2; i++)
            for(int j=y1; j<y2; j++) {
                if(flag[i][j])
                    sum--;
                flag[i][j] = true;
            }
    }

    // ������
    cout << sum << endl;

    return 0;
}
