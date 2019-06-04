#include "submit-2AddPointBeforeQueryPolygon.h"
#include "Operation.h"

using namespace std;

void SetEnvironmentFromAddPointBeforeQueryPolygon() {}

void AddPointFromAddPointBeforeQueryPolygon(int id, double x, double y) {
    Pointlist[id]=make_pair(x,y);
    Rectangle rec(x,y,x,y);
    MyTree.Insert(rec.p_min, rec.p_max, id);
}

std::vector<int> QueryPolygonFromAddPointBeforeQueryPolygon(int n, std::vector<std::pair<double,double> > &polygon) {
    RecIdAns.clear();
    PointIdAns.clear();

    Rectangle search_rec(polygon);
    MyTree.Search(search_rec.p_min, search_rec.p_max, MySearchCallback);

    for(int i=0;i<(int)RecIdAns.size();i++){
        if(CheckPoint(Pointlist[RecIdAns[i]].first, Pointlist[RecIdAns[i]].second, polygon) )
            PointIdAns.emplace_back(RecIdAns[i]);
    }
    return PointIdAns;
}
