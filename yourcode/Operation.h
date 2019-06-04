#ifndef OPERATION_H
#define OPERATION_H

#include "RTree.h"
#include <unordered_map>
#include <vector>

extern RTree<int,double,2,double> MyTree;
extern RTree<int,double,2,double> MyTree2;

extern std::unordered_map<int, std::vector<std::pair<double,double> > > Polylist;
extern std::unordered_map<int, std::pair<double,double> > Pointlist;
extern std::vector<int> RecIdAns;
extern std::vector<int> PolyIdAns;
extern std::vector<int> PointIdAns;

struct Rectangle{
    double p_min[2];
    double p_max[2];
    Rectangle(){}
    Rectangle(double minX,double minY,double maxX,double maxY){
        p_min[0]=minX;
        p_min[1]=minY;
        p_max[0]=maxX;
        p_max[1]=maxY;
    }
    Rectangle(std::vector<std::pair<double,double> >& polygon){
        double l=10000000.0,r=-10000000.0,u=-10000000.0,d=10000000.0;
        for(int i=0;i<(int)polygon.size();i++){
            std::pair<double,double> tp=polygon[i];
            l=std::min(l,tp.first);
            r=std::max(r,tp.first);
            u=std::max(u,tp.second);
            d=std::min(d,tp.second);
        }
        p_min[0]=l;
        p_min[1]=d;
        p_max[0]=r;
        p_max[1]=u;
    }
};

bool CheckPoint(double x, double y, std::vector<std::pair<double,double> >& poly);

bool MySearchCallback(int id);

#endif // OPERATION_H
