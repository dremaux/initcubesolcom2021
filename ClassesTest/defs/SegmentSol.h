/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   SegmentSol.h
 * Author: snir2g2
 *
 * Created on 19 mars 2019, 15:24
 */

#ifndef SEGMENTSOL_H
#define SEGMENTSOL_H

#include <chrono>
#include <thread>
#include "Protocole.h"
#include "SegmentVol.h"
#include "Message.h"

#define         DEVICE_PORT             "/dev/ttyUSB0" 

class SegmentVol;
class SegmentSol: public Protocole{
public:
    SegmentSol(SegmentVol *leSegment);
    virtual ~SegmentSol();
    void envoyerStatus();
    void envoyerMission();
    void envoyerMesure(string type);
    void activerReception();
    
private:
    SegmentVol* leSegment;
    Message* message;
    

};

#endif /* SEGMENTSOL_H */

