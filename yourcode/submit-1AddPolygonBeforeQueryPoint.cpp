#include "submit-1AddPolygonBeforeQueryPoint.h"
#include "Operation.h"

using namespace std;

bool MySearchCallback1(int id){
    RecIdAns.emplace_back(id);
    return true;
}

void SetEnvironmentFromAddPolygonBeforeQueryPoint() {
    MyTree.RemoveAll();
    Polylist.clear();
}

std::vector<int> QueryPointFromAddPolygonBeforeQueryPoint(double x, double y) {
    //cout<<"query:"<<x<<" "<<y<<endl;
    RecIdAns.clear();
    PolyIdAns.clear();
    Rectangle search_rec(x, y, x, y);
/*
      int itIndex = 0;
      RTree<int,double,2,double>::Iterator it;
      for( MyTree.GetFirst(it);
       !MyTree.IsNull(it);
       MyTree.GetNext(it) )
      {
        int value = MyTree.GetAt(it);

        double boundsMin[2] = {0,0};
        double boundsMax[2] = {0,0};
        it.GetBounds(boundsMin, boundsMax);
        cout << "it[" << itIndex++ << "] " << value << " = (" << boundsMin[0] << "," << boundsMin[1] << "," << boundsMax[0] << "," << boundsMax[1] << ")\n";
      }
*/
    MyTree.Search(search_rec.p_min, search_rec.p_max, MySearchCallback1);
    //cout<<RecIdAns.size()<<endl;
    for(int i=0;i<(int)RecIdAns.size();i++){
        if(CheckPoint(x,y, Polylist[RecIdAns[i]] ) )
            PolyIdAns.emplace_back(RecIdAns[i]);
    }
    //cout<<PolyIdAns.size()<<endl;
    return PolyIdAns;
}

void AddPolygonFromAddPolygonBeforeQueryPoint(int id, int n, std::vector<std::pair<double, double> > &polygon) {
    //polystore1.emplace_back(polygon);
    Polylist[id]=polygon;
    Rectangle rec(polygon);
    MyTree.Insert(rec.p_min, rec.p_max, id);
}
