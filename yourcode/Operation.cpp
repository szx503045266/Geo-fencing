#include "Operation.h"

using namespace std;

RTree<int,double,2,double> MyTree;
RTree<int,double,2,double> MyTree2;

unordered_map<int, vector<pair<double,double> > > Polylist;
unordered_map<int, pair<double,double> > Pointlist;
vector<int> RecIdAns;
vector<int> PolyIdAns;
vector<int> PointIdAns;

bool CheckPoint(double x, double y, vector<pair<double,double> >& poly){
    int times=0;
    for(int i=0;i<(int)poly.size();i++){
        pair<double,double> p1=poly[i], p2;
        if(i==(int)poly.size()-1)   //为了检测由队尾与队首两个点组成的边
            p2=poly[0];
        else
            p2=poly[i+1];
        //cout<<p1.first<<" "<<p1.second<<" "<<"&"<<" "<<p2.first<<" "<<p2.second<<endl;
        double xu, yu, xd ,yd;
        if(p1.second>p2.second){  //选出一个靠上的端点和一个靠下的端点
            xu=p1.first, yu=p1.second;
            xd=p2.first, yd=p2.second;
        }else{
            xu=p2.first, yu=p2.second;
            xd=p1.first, yd=p1.second;
        }
        if((x==xu&&y==yu)||(x==xd&&y==yd)||(yu==y&&yd==y))
            return false;
        if(y<=yu&&y>yd){
            double xt=xu-(yu-y)*(xu-xd)/(yu-yd);
            if(xt>x)
                times++;
        }
    }
    return (times%2) ? true : false;
}

bool MySearchCallback(int id){
    RecIdAns.emplace_back(id);
    return true;
}
