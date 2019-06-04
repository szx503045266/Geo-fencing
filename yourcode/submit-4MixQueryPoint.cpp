#include "submit-4MixQueryPoint.h"
#include "Operation.h"

using namespace std;

void SetEnvironmentFromMixQueryPoint() {}

std::vector<int> QueryPointFromMixQueryPoint(double x, double y) {
    RecIdAns.clear();
    PolyIdAns.clear();
    Rectangle search_rec(x, y, x, y);
    MyTree.Search(search_rec.p_min, search_rec.p_max, MySearchCallback);
    for(int i=0;i<(int)RecIdAns.size();i++){
        if(CheckPoint(x,y,Polylist[RecIdAns[i]] ) )
            PolyIdAns.emplace_back(RecIdAns[i]);
    }
    return PolyIdAns;
}

void AddPolygonFromMixQueryPoint(int id, int n, std::vector<std::pair<double,double> > &polygon) {
    Polylist[id]=polygon;
    Rectangle rec(polygon);
    MyTree.Insert(rec.p_min, rec.p_max, id);
}

void DeletePolygonFromMixQueryPoint(int id) {
    Rectangle rec(Polylist[id]);
    MyTree.Remove(rec.p_min, rec.p_max ,id);
}
