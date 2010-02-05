/*
 
  MBDist.h - Distorsion Effect

  Copyright (C) 2002-2005 Nasca Octavian Paul
  Author: Nasca Octavian Paul
  ZynAddSubFX - a software synthesizer

  Modified for rakarrack by Josep Andreu & Hernan Ordiales
  
  This program is free software; you can redistribute it and/or modify
  it under the terms of version 2 of the GNU General Public License 
  as published by the Free Software Foundation.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License (version 2) for more details.

  You should have received a copy of the GNU General Public License (version 2)
  along with this program; if not, write to the Free Software Foundation,
  Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307 USA

*/

#ifndef MBDIST_H
#define MBDIST_H

#include "global.h"
#include "AnalogFilter.h"


class MBDist
{
public:
  MBDist (REALTYPE * efxoutl_, REALTYPE * efxoutr_);
  ~MBDist ();
  void out (REALTYPE * smpsl, REALTYPE * smpr);
  void setpreset (int npreset);
  void changepar (int npar, int value);
  int getpar (int npar);
  void cleanup ();

  int Ppreset;
  REALTYPE *efxoutl;
  REALTYPE *efxoutr;
  REALTYPE *lowl;
  REALTYPE *lowr;
  REALTYPE *midl;
  REALTYPE *midr;
  REALTYPE *highl;
  REALTYPE *highr;
  
  REALTYPE outvolume;
  REALTYPE volume;

private:


  //Parametrii
  int Pvolume;	//Volumul or E/R
  int Ppanning;	//Panning
  int Plrcross;	// L/R Mixing
  int Pdrive;		//the input amplification
  int Plevel;		//the ouput amplification
  int PtypeL;
  int PtypeM;
  int PtypeH;
  int PvolL;
  int PvolM;
  int PvolH;
  int PdriveL;
  int PdriveM;
  int PdriveH;
  		//MBDist type
  int Pnegate;	//if the input is negated 
  int Cross1;		//lowpass filter
  int Cross2;		//highpass filter
  int Pstereo;	//0=mono,1=stereo
  
  void setvolume (int Pvolume);
  void setpanning (int Ppanning);
  void setlrcross (int Plrcross);
  void setCross1 (int value);
  void setCross2 (int value);

  //Parametrii reali
  REALTYPE panning, lrcross;
  float volL,volM,volH;
  AnalogFilter *lpf1l, *lpf1r, *hpf1l, *hpf1r;
  AnalogFilter *lpf2l, *lpf2r, *hpf2l, *hpf2r;
  

};


#endif