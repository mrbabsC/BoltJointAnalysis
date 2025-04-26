// Include guards to prevent multiple inclusions
#ifndef MYHEADER_H
#define MYHEADER_H

//Declaration of function to select cross sectional area of bolt At [mm2]
float bolt_At(int boltsize);

//Declaration of function to Calculate Bolt Preload (Fi)
int calcboltpreload(float x, int y, float z);

//Declaration of function to Calculate Load Sharing (Joint Stiffness)
int jointstiffness(int x, int y);

//Declaration of function to Check Bolt Stress
int checkboltstress(int x, float y);

//Declaration of Factor of Safety
float factor_safety(int x, int y);

#endif