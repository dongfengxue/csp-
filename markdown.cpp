#include<iostream>
#include<string>
#include<vector>
#include<cstdlib>

using namespace std;

const int NOVALUE = -1;
const int TRUE = -2;
const int FALSE = -3;

struct _permission{
    string category;
    int level;
};    //权限
vector <_permission> permission;

struct _role{
    string role;
    int num;
    vector <_permission> permission;
};
vector <_role> role;

struct _user{
    string user;
    int num;
    vector <_role> role;
};
vector <_user> user;

string get_category(string& s){
        int pos=s.find(":");
        if(pos==(int)string::npos)
            return s;      //表示无等级查询
        else
            return s.substr(0,pos);
}

int get_level(string& s){
    int pos=s.find(":");
    if(pos==(int)string::npos)
        return NOVALUE;
    else
        return atoi(s.substr(pos+1,s.length()-1).c_str());

}
int privilegematch(_permission& p1, _permission& p2)
{
    if(p1.category != p2.category)
        return FALSE;
    else if(p2.level == NOVALUE) {
        // 不分等级查询
        if(p1.level == NOVALUE)
            return TRUE;
        else
            return p1.level;
    } else {    // p2.level >= 0
        // 分等级查询
        if(p1.level == NOVALUE)
            return TRUE;
        else {
            if(p1.level >= p2.level)
                return TRUE;
            else
                return FALSE;
        }
    }
}
int rolematch(string& rl, _permission& prvl)
{
    int ans = FALSE;

    for(int i=0; i<(int)role.size(); i++) {
        if(role[i].role == rl) {
            for(int j=0; j<role[i].num; j++) {
                int rt = privilegematch(role[i].permission[j], prvl);
                if(rt > ans)
                    ans = rt;
            }
        }
    }

    return ans;
}
int query(string& usr, _permission& prvl)
{
    for(int i=0; i<(int)user.size(); i++) {
        if(user[i].user == usr) {
            int ans = FALSE;
            for(int j=0; j<user[i].num; j++) {
                int rt = rolematch(user[i].role[j], prvl);
                if(rt > ans)
                    ans = rt;
            }
            return ans;
        }
    }

    return FALSE;
}
int main(){
int p;
int s;
cin>>p;
_permission per;
for(int i=0;i<p;i++)        //得到权限
{
    cin>>s;
    per.category=get_category(s);
    per.level=get_level(s);
    permission.push_back(per);
}
int r;
cin>>u;
for(int i=0;i<r;i++)            //输入角色
  {
      _role r1;
      cin>>r1.role;
      cin>>r1.num;
      for(int j=0;j<r1.num;j++)
      {
          cin>>s;
          per.category=get_category(s);
          per.level=get_level(s);
          r1.permission.push_back(per);
      }
      role.push_back(r1);
  }
int u;
cin>>u;             //输入用户
for(int i=0;i<u;i++)
{
    _user us;
    cin>>us.user;
    cin>>us.num;
    for(int j=0;j<us.num;j++)
    {
        cin>>s;
        us.role.push_back(s);
    }
    user.puch_back(us);
}

int q;
cin>>q;
for(int i=0;i<q;i++)
{
    string suser,p1;
    cin>>suser>>p1;
            // 权限分解
        prvl.category = get_category(p1);
        prvl.level = get_level(p1);

        // 查询处理
        int ans = query(suser, prvl);

        // 输出结果
        if(ans == TRUE)
            cout << "true" << endl;
        else if(ans == FALSE)
            cout << "false" << endl;
        else
            cout << ans << endl;

}
return 0;
}
