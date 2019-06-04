#include "submit-3AddBeforeQuery.h"
#include "Operation.h"

using namespace std;

void SetEnvironmentFromAddBeforeQuery() {}

void AddPointFromAddBeforeQuery(int id, double x, double y) {
    Pointlist[id]=make_pair(x,y);
    Rectangle rec(x,y,x,y);
    MyTree2.Insert(rec.p_min, rec.p_max, id);
}

void AddPolygonFromAddBeforeQuery(int id, int n, std::vector<std::pair<double,double> > &polygon) {
    Polylist[id]=polygon;
    Rectangle rec(polygon);
    MyTree.Insert(rec.p_min, rec.p_max, id);
}

std::vector<int> QueryPointFromAddBeforeQuery(double x, double y) {
    RecIdAns.clear();
    PolyIdAns.clear();
    Rectangle search_rec(x, y, x, y);

    MyTree.Search(search_rec.p_min, search_rec.p_max, MySearchCallback);
    for(int i=0;i<(int)RecIdAns.size();i++){
        if(CheckPoint(x,y, Polylist[RecIdAns[i]] ) )
            PolyIdAns.emplace_back(RecIdAns[i]);
    }
    return PolyIdAns;
}

std::vector<int> QueryPolygonFromAddBeforeQuery(int n, std::vector<std::pair<double,double> > &polygon) {
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
