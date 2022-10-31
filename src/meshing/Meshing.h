//
// Created by wbmcg on 31/10/2022.
//

#ifndef AEROSIM_MESHING_H
#define AEROSIM_MESHING_H


class Meshing {
public:
    Meshing();
private:
    float **vertices{};
    float **cells{};
};


#endif //AEROSIM_MESHING_H
