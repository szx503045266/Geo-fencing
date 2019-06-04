#include "submit-6MixQuery.h"
#include "Operation.h"

using namespace std;

unordered_map<int,int> DeletePolylist;

void SetEnvironmentFromMixQuery() {}

void AddPointFromMixQuery(int id, double x, double y) {
    Pointlist[id]=make_pair(x,y);
    Rectangle rec(x,y,x,y);
    MyTree2.Insert(rec.p_min, rec.p_max, id);
}

void DeletePointFromMixQuery(int id) {
    pair<double,double> tp=Pointlist[id];
    Rectangle rec(tp.first,tp.second,tp.first,tp.second);
    MyTree2.Remove(rec.p_min, rec.p_max ,id);
}

std::vector<int> QueryPointFromMixQuery(double x, double y) {
    RecIdAns.clear();
    PolyIdAns.clear();
    Rectangle search_rec(x, y, x, y);

    MyTree.Search(search_rec.p_min, search_rec.p_max, MySearchCallback);
    for(int i=0;i<(int)RecIdAns.size();i++){
        if(DeletePolylist[RecIdAns[i]]==0&&CheckPoint(x,y, Polylist[RecIdAns[i]] ) )
            PolyIdAns.emplace_back(RecIdAns[i]);
    }
    return PolyIdAns;
}

void AddPolygonFromMixQuery(int id, int n, std::vector<std::pair<double,double> > &polygon) {
    Polylist[id]=polygon;
    Rectangle rec(polygon);
    MyTree.Insert(rec.p_min, rec.p_max, id);
}

void DeletePolygonFromMixQuery(int id) {
    //Rectangle rec(Polylist[id]);
    //MyTree.Remove(rec.p_min, rec.p_max ,id);
    DeletePolylist[id]=1;
}

std::vector<int> QueryPolygonFromMixQuery(int n, std::vector<std::pair<double,double> > &polygon) {
    RecIdAns.clear();
    PointIdAns.clear();
    Rectangle search_rec(polygon);
    MyTree2.Search(search_rec.p_min, search_rec.p_max, MySearchCallback);

    for(int i=0;i<(int)RecIdAns.size();i++){
        if(CheckPoint(Pointlist[RecIdAns[i]].first, Pointlist[RecIdAns[i]].second, polygon) )
            PointIdAns.emplace_back(RecIdAns[i]);
    }
    return PointIdAns;
}

