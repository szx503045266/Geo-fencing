//
// Created by zhang on 18-12-4.
//

#include "submit-5MixQueryPolygon.h"
#include "Operation.h"

using namespace std;

bool MySearchCallback5(int id){
    RecIdAns.emplace_back(id);
    return true;
}

void SetEnvironmentFromMixQueryPolygon() {
    MyTree.RemoveAll();
    Pointlist.clear();
}

void AddPointFromMixQueryPolygon(int id, double x, double y) {
    Pointlist[id]=make_pair(x,y);
    Rectangle rec(x,y,x,y);
    MyTree.Insert(rec.p_min, rec.p_max, id);
}

void DeletePointFromMixQueryPolygon(int id) {
    pair<double,double> tp=Pointlist[id];
    Rectangle rec(tp.first,tp.second,tp.first,tp.second);
    MyTree.Remove(rec.p_min, rec.p_max ,id);
}

std::vector<int> QueryPolygonFromMixQueryPolygon(int n, std::vector<std::pair<double, double> > &polygon) {
    RecIdAns.clear();
    PointIdAns.clear();

    Rectangle search_rec(polygon);
    MyTree.Search(search_rec.p_min, search_rec.p_max, MySearchCallback5);

    for(int i=0;i<(int)RecIdAns.size();i++){
        if(CheckPoint(Pointlist[RecIdAns[i]].first,  Pointlist[RecIdAns[i]].second, polygon) )
            PointIdAns.emplace_back(RecIdAns[i]);
    }
    return PointIdAns;
}
