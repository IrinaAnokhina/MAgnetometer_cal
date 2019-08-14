
#include "Calculations.h"

extern float calibrated_values[3];

int filterAX(int x, int Nb, int k){char cyc = 100;	static int y[100] = {0};static char num =  0;static int z = 0;int ret=0;y[z]=x;z++; if (z==cyc)z=0;for (char i = 0; i<(cyc);i++)ret+=y[i];return (ret/cyc);}
int filterAY(int x, int Nb, int k){char cyc = 100;	static int y[100] = {0};static char num =  0;static int z = 0;int ret=0;y[z]=x;z++; if (z==cyc)z=0;for (char i = 0; i<(cyc);i++)ret+=y[i];return (ret/cyc);}
int filterAZ(int x, int Nb, int k){char cyc = 100;	static int y[100] = {0};static char num =  0;static int z = 0;int ret=0;y[z]=x;z++; if (z==cyc)z=0;for (char i = 0; i<(cyc);i++)ret+=y[i];return (ret/cyc);}
int filterGX(int x, int Nb, int k){char cyc = 100;	static int y[100] = {0};static char num =  0;static int z = 0;int ret=0;y[z]=x;z++; if (z==cyc)z=0;for (char i = 0; i<(cyc);i++)ret+=y[i];return (ret/cyc);}
int filterGY(int x, int Nb, int k){char cyc = 100;	static int y[100] = {0};static char num =  0;static int z = 0;int ret=0;y[z]=x;z++; if (z==cyc)z=0;for (char i = 0; i<(cyc);i++)ret+=y[i];return (ret/cyc);}
int filterGZ(int x, int Nb, int k){char cyc = 100;	static int y[100] = {0};static char num =  0;static int z = 0;int ret=0;y[z]=x;z++; if (z==cyc)z=0;for (char i = 0; i<(cyc);i++)ret+=y[i];return (ret/cyc);}
int filterMX(int x, int Nb, int k){char cyc = 100;	static int y[100] = {0};static char num =  0;static int z = 0;int ret=0;y[z]=x;z++; if (z==cyc)z=0;for (char i = 0; i<(cyc);i++)ret+=y[i];return (ret/cyc);}
int filterMY(int x, int Nb, int k){char cyc = 100;	static int y[100] = {0};static char num =  0;static int z = 0;int ret=0;y[z]=x;z++; if (z==cyc)z=0;for (char i = 0; i<(cyc);i++)ret+=y[i];return (ret/cyc);}

int filterMZ(int x, int Nb, int k)
{
char cyc = 100;
static int y[100] = {0};
static char num =  0;
static int z = 0;
int ret=0;
y[z]=x;
z++;
if (z==cyc)z=0;
for (char i = 0; i<(cyc);i++)ret+=y[i];
return (ret/cyc);
}

float filterEXP(int x, float Xfilt, float a)
{
	float Xf = x;
	return (Xfilt*a + Xf*(1.0-a));
}

void transformation_MAG(float uncalibrated_values[3])    
{
  //MAGNETOMETR calibration_matrix[3][3] is the transformation matrix 
//replace M11, M12,..,M33 with your transformation matrix data  
 double calibration_matrix[3][3] =  
 { 
    { 1.142,      0.058,     -0.004  }, 
    { 0.025,      1.154,     -0.007  }, 
    { -0.038,      0.005,     1.406  } 
 };

  //bias[3] is the bias 
  //replace Bx, By, Bz with your bias data 
 double bias[3] = 
 {     
      -176.403, 
      887.386, 
      -2115.514 
 };
      
  //calculation
  for (int i=0; i<3; ++i) uncalibrated_values[i] = uncalibrated_values[i] - bias[i];
  float result[3] = {0, 0, 0};
  for (int i=0; i<3; ++i)
    for (int j=0; j<3; ++j)
      result[i] += calibration_matrix[i][j] * uncalibrated_values[j];
  for (int i=0; i<3; ++i) calibrated_values[i] = result[i];
}

void transformation_AXEL(float uncalibrated_values[3])    
{
  //AXELEROMETR calibration_matrix[3][3] is the transformation matrix 
//replace M11, M12,..,M33 with your transformation matrix data  
 double calibration_matrix[3][3] =  
 { 
    { 1,      0.006,     0.005  }, 
    { -0.01,      1.004,     -0.001  }, 
    { -0.015,      0.002,     0.998  } 
 };

  //bias[3] is the bias 
  //replace Bx, By, Bz with your bias data 
 double bias[3] = 
 {     
      430.937, 
      -487.281, 
      47.478 
 };
      
  //calculation
  for (int i=0; i<3; ++i) uncalibrated_values[i] = uncalibrated_values[i] - bias[i];
  float result[3] = {0, 0, 0};
  for (int i=0; i<3; ++i)
    for (int j=0; j<3; ++j)
      result[i] += calibration_matrix[i][j] * uncalibrated_values[j];
  for (int i=0; i<3; ++i) calibrated_values[i] = result[i];
}

/**
* Azimuth (degree), calculated from axis X to the north
*/
float Fi_Azimuth(MTVec3D axel, MTVec3D magn)
{
	// axel - axelerometer values
	// magn - magnetometer values

	// local direction to the east
	MTVec3D e = mtCrossProduct3D(axel, magn);

	// local direction to the north
	MTVec3D n = mtCrossProduct3D(e, axel);

	// azimuth as an angle of n in the local plane XY
	// convert radians to degrees
	return (float )(atan2((double)n.y, (double)n.x)*180.0 / MT_PI);
}