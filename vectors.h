//use templates
//TODO:use operater () 
//     and duble the // symbles bool && ==


#ifndef VECTORS_H
#define VECTORS_H

struct v2
{
	int x,y;

	v2(){};
	v2(int x,int y){this->x = x,this->y = y;};
	void set(int x,int y){this->x = x,this->y = y;};

	v2 operator = (v2 v2r) {this->x=v2r.x;this->y=v2r.y;return v2r;};
	v2 operator + (v2 v2r) {v2 sum;sum.x = this->x+v2r.x;sum.y = this->y+v2r.y;return sum;};
	v2 operator - (v2 v2r) {v2 sum;sum.x = this->x-v2r.x;sum.y = this->y-v2r.y;return sum;};
	v2 operator * (v2 v2r) {v2 sum;sum.x = this->x*v2r.x;sum.y = this->y*v2r.y;return sum;};
	v2 operator / (v2 v2r) {v2 sum;sum.x = this->x/v2r.x;sum.y = this->y/v2r.y;return sum;};

	v2 operator () (int x,int y) {this->x = x;this->y = y;return(v2(x,y));}; //
	v2 operator () (v2 v2r) {this->x=v2r.x;this->y=v2r.y;return v2r;}; //

	v2 operator = (int v2r) {this->x=v2r;this->y=v2r;return v2(this->x,this->y);};
	v2 operator + (int v2r) {v2 sum;sum.x = this->x+v2r;sum.y = this->y+v2r;return sum;};
	v2 operator - (int v2r) {v2 sum;sum.x = this->x-v2r;sum.y = this->y-v2r;return sum;};
	v2 operator * (int v2r) {v2 sum;sum.x = this->x*v2r;sum.y = this->y*v2r;return sum;};
	v2 operator / (int v2r) {v2 sum;sum.x = this->x/v2r;sum.y = this->y/v2r;return sum;};	

	bool operator != (v2 v2r) { if (this->x != v2r.x && this->y != v2r.y) { return true; } else return false; };

	bool operator == (v2 v2r) { if (this->x == v2r.x && this->y == v2r.y) { return true; } else return false; };
	bool operator <  (v2 v2r) { if (this->x< v2r.x && this->y< v2r.y) { return true; } else return false; };
	bool operator >  (v2 v2r) { if (this->x> v2r.x && this->y> v2r.y) { return true; } else return false; };
	bool operator <= (v2 v2r) { if (this->x <= v2r.x && this->y <= v2r.y) { return true; } else return false; };
	bool operator >= (v2 v2r) { if (this->x >= v2r.x && this->y >= v2r.y) { return true; } else return false; };

	bool operator != (int v2r) { if (this->x != v2r && this->y != v2r) { return true; } else return false; };

	bool operator == (int v2r) { if (this->x == v2r && this->y == v2r) { return true; } else return false; };
	bool operator <  (int v2r) { if (this->x< v2r && this->y< v2r) { return true; } else return false; };
	bool operator >  (int v2r) { if (this->x> v2r && this->y> v2r) { return true; } else return false; };
	bool operator <= (int v2r) { if (this->x <= v2r && this->y <= v2r) { return true; } else return false; };
	bool operator >= (int v2r) { if (this->x >= v2r && this->y >= v2r) { return true; } else return false; };

};

struct v2f
{
	float x,y;
	v2f(){};
	v2f(float x,float y){this->x = x,this->y = y;};
	void set(float x,float y){this->x = x,this->y = y;};

	v2f operator = (v2f v2fr) {this->x=v2fr.x;this->y=v2fr.y;return v2fr;};
	v2f operator + (v2f v2fr) {v2f sum;sum.x = this->x+v2fr.x;sum.y = this->y+v2fr.y;return sum;};
	v2f operator - (v2f v2fr) {v2f sum;sum.x = this->x-v2fr.x;sum.y = this->y-v2fr.y;return sum;};
	v2f operator * (v2f v2fr) {v2f sum;sum.x = this->x*v2fr.x;sum.y = this->y*v2fr.y;return sum;};
	v2f operator / (v2f v2fr) {v2f sum;sum.x = this->x/v2fr.x;sum.y = this->y/v2fr.y;return sum;};	

	v2f operator () (float x,float y) {this->x = x;this->y = y;return v2f(x,y);}; // 
	v2f operator () (v2f v2fr) {this->x=v2fr.x;this->y=v2fr.y;return v2fr;}; //

	v2f operator = (float v2fr) {this->x=v2fr;this->y=v2fr;return v2f(this->x,this->y);};
	v2f operator + (float v2fr) {v2f sum;sum.x = this->x+v2fr;sum.y = this->y+v2fr;return sum;};
	v2f operator - (float v2fr) {v2f sum;sum.x = this->x-v2fr;sum.y = this->y-v2fr;return sum;};
	v2f operator * (float v2fr) {v2f sum;sum.x = this->x*v2fr;sum.y = this->y*v2fr;return sum;};
	v2f operator / (float v2fr) {v2f sum;sum.x = this->x/v2fr;sum.y = this->y/v2fr;return sum;};

	bool operator != (v2f v2fr) { if (this->x != v2fr.x && this->y != v2fr.y) { return true; } else return false; };

	bool operator == (v2f v2fr) { if (this->x == v2fr.x && this->y == v2fr.y) { return true; } else return false; };
	bool operator <  (v2f v2fr) { if (this->x< v2fr.x && this->y< v2fr.y) { return true; } else return false; };
	bool operator >  (v2f v2fr) { if (this->x> v2fr.x && this->y> v2fr.y) { return true; } else return false; };
	bool operator <= (v2f v2fr) { if (this->x <= v2fr.x && this->y <= v2fr.y) { return true; } else return false; };
	bool operator >= (v2f v2fr) { if (this->x >= v2fr.x && this->y >= v2fr.y) { return true; } else return false; };

	bool operator != (float v2fr) { if (this->x != v2fr && this->y != v2fr) { return true; } else return false; };

	bool operator == (float v2fr) { if (this->x == v2fr && this->y == v2fr) { return true; } else return false; };
	bool operator <  (float v2fr) { if (this->x< v2fr && this->y< v2fr) { return true; } else return false; };
	bool operator >  (float v2fr) { if (this->x> v2fr && this->y> v2fr) { return true; } else return false; };
	bool operator <= (float v2fr) { if (this->x <= v2fr && this->y <= v2fr) { return true; } else return false; };
	bool operator >= (float v2fr) { if (this->x >= v2fr && this->y >= v2fr) { return true; } else return false; };
};

struct v3
{
	int x,y,z;
	v3(){};
	v3      (int x,int y,int z){this->x = x,this->y = y;this->z= z;};
	void set(int x,int y,int z){this->x = x,this->y = y;this->z= z;};
	
	v3 operator = (v3 v3r) {this->x=v3r.x;this->y=v3r.y;this->z=v3r.z;return v3r;};
	v3 operator + (v3 v3r) {v3 sum;sum.x = this->x+v3r.x;sum.y = this->y+v3r.y;sum.z = this->z+v3r.z;return sum;};
	v3 operator - (v3 v3r) {v3 sum;sum.x = this->x-v3r.x;sum.y = this->y-v3r.y;sum.z = this->z-v3r.z;return sum;};
	v3 operator * (v3 v3r) {v3 sum;sum.x = this->x*v3r.x;sum.y = this->y*v3r.y;sum.z = this->z*v3r.z;return sum;};
	v3 operator / (v3 v3r) {v3 sum;sum.x = this->x/v3r.x;sum.y = this->y/v3r.y;sum.z = this->z/v3r.z;return sum;};

	v3 operator () (int x,int y,int z) {this->x = x;this->y = y;this->z = z;return(v3(x,y,z));}; //
	v3 operator () (v3 v3r) {this->x=v3r.x;this->y=v3r.y;this->z=v3r.z;return v3r;};//

	v3 operator = (int v3r) {this->x=v3r;this->y=v3r;this->z=v3r;return v3(this->x,this->y,this->z);};
	v3 operator + (int v3r) {v3 sum;sum.x = this->x+v3r;sum.y = this->y+v3r;sum.z = this->z+v3r;return sum;};
	v3 operator - (int v3r) {v3 sum;sum.x = this->x-v3r;sum.y = this->y-v3r;sum.z = this->z-v3r;return sum;};
	v3 operator * (int v3r) {v3 sum;sum.x = this->x*v3r;sum.y = this->y*v3r;sum.z = this->z*v3r;return sum;};
	v3 operator / (int v3r) {v3 sum;sum.x = this->x/v3r;sum.y = this->y/v3r;sum.z = this->z/v3r;return sum;};

	bool operator != (v3 v3r) { if (this->x != v3r.x && this->y != v3r.y && this->z != v3r.z) { return true; } else return false; };

	bool operator == (v3 v3r) { if (this->x == v3r.x && this->y == v3r.y && this->z == v3r.z) { return true; } else return false; };
	bool operator <  (v3 v3r) { if (this->x< v3r.x && this->y< v3r.y && this->z< v3r.z) { return true; } else return false; };
	bool operator >  (v3 v3r) {if(this->x> v3r.x&&this->y> v3r.y&&this->z> v3r.z){return true;}else return false;};
	bool operator <= (v3 v3r) {if(this->x<=v3r.x&&this->y<=v3r.y&&this->z<=v3r.z){return true;}else return false;};
	bool operator >= (v3 v3r) {if(this->x>=v3r.x&&this->y>=v3r.y&&this->z>=v3r.z){return true;}else return false;};

	bool operator != (int v3r) {if(this->x!=v3r&&this->y!=v3r&&this->z!=v3r){return true;}else return false;};

	bool operator == (int v3r) {if(this->x==v3r&&this->y==v3r&&this->z==v3r){return true;}else return false;};
	bool operator <  (int v3r) {if(this->x< v3r&&this->y< v3r&&this->z< v3r){return true;}else return false;};
	bool operator >  (int v3r) {if(this->x> v3r&&this->y> v3r&&this->z> v3r){return true;}else return false;};
	bool operator <= (int v3r) {if(this->x<=v3r&&this->y<=v3r&&this->z<=v3r){return true;}else return false;};
	bool operator >= (int v3r) {if(this->x>=v3r&&this->y>=v3r&&this->z>=v3r){return true;}else return false;};
};

struct v3f
{
	float x,y,z;
	v3f(){};
	v3f      (float x,float y,float z){this->x = x;this->y = y;this->z= z;};
	void set(float x,float y,float z){this->x = x;this->y = y;this->z= z;};
	
	v3f operator = (v3f v3fr) {this->x=v3fr.x;this->y=v3fr.y;this->z=v3fr.z;return v3fr;};
	v3f operator + (v3f v3fr) {v3f sum;sum.x = this->x+v3fr.x;sum.y = this->y+v3fr.y;sum.z = this->z+v3fr.z;return sum;};
	v3f operator - (v3f v3fr) {v3f sum;sum.x = this->x-v3fr.x;sum.y = this->y-v3fr.y;sum.z = this->z-v3fr.z;return sum;};
	v3f operator * (v3f v3fr) {v3f sum;sum.x = this->x*v3fr.x;sum.y = this->y*v3fr.y;sum.z = this->z*v3fr.z;return sum;};
	v3f operator / (v3f v3fr) {v3f sum;sum.x = this->x/v3fr.x;sum.y = this->y/v3fr.y;sum.z = this->z/v3fr.z;return sum;};

	v3f operator () (float x,float y,float z) {this->x = x;this->y = y;this->z = z;return v3f(x,y,z);}; //
	v3f operator () (v3f v3fr) {this->x=v3fr.x;this->y=v3fr.y;this->z=v3fr.z;return v3fr;}; //

	v3f operator = (float v3fr) {this->x=v3fr;this->y=v3fr;this->z=v3fr;return v3f(this->x,this->y,this->z);};
	v3f operator + (float v3fr) {v3f sum;sum.x = this->x+v3fr;sum.y = this->y+v3fr;sum.z = this->z+v3fr;return sum;};
	v3f operator - (float v3fr) {v3f sum;sum.x = this->x-v3fr;sum.y = this->y-v3fr;sum.z = this->z-v3fr;return sum;};
	v3f operator * (float v3fr) {v3f sum;sum.x = this->x*v3fr;sum.y = this->y*v3fr;sum.z = this->z*v3fr;return sum;};
	v3f operator / (float v3fr) {v3f sum;sum.x = this->x/v3fr;sum.y = this->y/v3fr;sum.z = this->z/v3fr;return sum;};

	bool operator != (v3f v3fr) {if(this->x!=v3fr.x&&this->y!=v3fr.y&&this->z!=v3fr.z){return true;}else return false;};

	bool operator == (v3f v3fr) {if(this->x==v3fr.x&&this->y==v3fr.y&&this->z==v3fr.z){return true;}else return false;};
	bool operator <  (v3f v3fr) {if(this->x< v3fr.x&&this->y< v3fr.y&&this->z< v3fr.z){return true;}else return false;};
	bool operator >  (v3f v3fr) {if(this->x> v3fr.x&&this->y> v3fr.y&&this->z> v3fr.z){return true;}else return false;};
	bool operator <= (v3f v3fr) {if(this->x<=v3fr.x&&this->y<=v3fr.y&&this->z<=v3fr.z){return true;}else return false;};
	bool operator >= (v3f v3fr) {if(this->x>=v3fr.x&&this->y>=v3fr.y&&this->z>=v3fr.z){return true;}else return false;};

	bool operator != (float v3fr) {if(this->x!=v3fr&&this->y!=v3fr&&this->z!=v3fr){return true;}else return false;};

	bool operator == (float v3fr) {if(this->x==v3fr&&this->y==v3fr&&this->z==v3fr){return true;}else return false;};
	bool operator <  (float v3fr) {if(this->x< v3fr&&this->y< v3fr&&this->z< v3fr){return true;}else return false;};
	bool operator >  (float v3fr) {if(this->x> v3fr&&this->y> v3fr&&this->z> v3fr){return true;}else return false;};
	bool operator <= (float v3fr) {if(this->x<=v3fr&&this->y<=v3fr&&this->z<=v3fr){return true;}else return false;};
	bool operator >= (float v3fr) {if(this->x>=v3fr&&this->y>=v3fr&&this->z>=v3fr){return true;}else return false;};
};

struct v4
{
	int x1,y1,x2,y2;
	v4(){};
	v4      (int x1,int y1,int x2,int y2){this->x1 = x1;this->y1 = y1;this->x2 = x2;this->y2 = y2;};
	void set(int x1,int y1,int x2,int y2){this->x1 = x1;this->y1 = y1;this->x2 = x2;this->y2 = y2;};

	v4 operator = (v4 v4r) {this->x1=v4r.x1;this->y1=v4r.y1; this->x2=v4r.x2;this->y2=v4r.y2; return v4r;};
	v4 operator + (v4 v4r) {v4 sum;sum.x1 = this->x1+v4r.x1;sum.y1 = this->y1+v4r.y1; sum.x2 = this->x2+v4r.x2;sum.y2 = this->y2+v4r.y2;return sum;};
	v4 operator - (v4 v4r) {v4 sum;sum.x1 = this->x1-v4r.x1;sum.y1 = this->y1-v4r.y1; sum.x2 = this->x2-v4r.x2;sum.y2 = this->y2-v4r.y2;return sum;};
	v4 operator * (v4 v4r) {v4 sum;sum.x1 = this->x1*v4r.x1;sum.y1 = this->y1*v4r.y1; sum.x2 = this->x2*v4r.x2;sum.y2 = this->y2*v4r.y2;return sum;};
	v4 operator / (v4 v4r) {v4 sum;sum.x1 = this->x1/v4r.x1;sum.y1 = this->y1/v4r.y1; sum.x2 = this->x2/v4r.x2;sum.y2 = this->y2/v4r.y2;return sum;};

	v4 operator () (int x1,int y1,int x2,int y2){this->x1 = x1;this->y1 = y1;this->x2 = x2;this->y2 = y2;return(v4(x1,y1,x2,y2));}; //
	v4 operator () (v4 v4r) {this->x1=v4r.x1;this->y1=v4r.y1; this->x2=v4r.x2;this->y2=v4r.y2; return v4r;}; //

	v4 operator = (int v4r) {this->x1=v4r;this->y1=v4r; this->x2=v4r;this->y2=v4r; return v4(this->x1,this->y1,this->x2,this->y2);};
	v4 operator + (int v4r) {v4 sum;sum.x1 = this->x1+v4r;sum.y1 = this->y1+v4r; sum.x2 = this->x2+v4r;sum.y2 = this->y2+v4r;return sum;};
	v4 operator - (int v4r) {v4 sum;sum.x1 = this->x1-v4r;sum.y1 = this->y1-v4r; sum.x2 = this->x2-v4r;sum.y2 = this->y2-v4r;return sum;};
	v4 operator * (int v4r) {v4 sum;sum.x1 = this->x1*v4r;sum.y1 = this->y1*v4r; sum.x2 = this->x2*v4r;sum.y2 = this->y2*v4r;return sum;};
	v4 operator / (int v4r) {v4 sum;sum.x1 = this->x1/v4r;sum.y1 = this->y1/v4r; sum.x2 = this->x2/v4r;sum.y2 = this->y2/v4r;return sum;};

	bool operator != (v4 v4r) {if(this->x1!=v4r.x1&&this->y1!=v4r.y1 && this->x2!=v4r.x2&&this->y2!=v4r.y2){return true;}else return false;};

	bool operator == (v4 v4r) {if(this->x1==v4r.x1&&this->y1==v4r.y1 && this->x2==v4r.x2&&this->y2==v4r.y2){return true;}else return false;};
	bool operator <  (v4 v4r) {if(this->x1< v4r.x1&&this->y1< v4r.y1 && this->x2< v4r.x2&&this->y2< v4r.y2){return true;}else return false;};
	bool operator >  (v4 v4r) {if(this->x1> v4r.x1&&this->y1> v4r.y1 && this->x2> v4r.x2&&this->y2> v4r.y2){return true;}else return false;};
	bool operator <= (v4 v4r) {if(this->x1<=v4r.x1&&this->y1<=v4r.y1 && this->x2<=v4r.x2&&this->y2<=v4r.y2){return true;}else return false;};
	bool operator >= (v4 v4r) {if(this->x1>=v4r.x1&&this->y1>=v4r.y1 && this->x2<=v4r.x2&&this->y2<=v4r.y2){return true;}else return false;};
	
	bool operator != (int v4r) {if(this->x1!=v4r&&this->y1!=v4r && this->x2!=v4r&&this->y2!=v4r){return true;}else return false;};

	bool operator == (int v4r) {if(this->x1==v4r&&this->y1==v4r && this->x2==v4r&&this->y2==v4r){return true;}else return false;};
	bool operator <  (int v4r) {if(this->x1< v4r&&this->y1< v4r && this->x2< v4r&&this->y2< v4r){return true;}else return false;};
	bool operator >  (int v4r) {if(this->x1> v4r&&this->y1> v4r && this->x2> v4r&&this->y2> v4r){return true;}else return false;};
	bool operator <= (int v4r) {if(this->x1<=v4r&&this->y1<=v4r && this->x2<=v4r&&this->y2<=v4r){return true;}else return false;};
	bool operator >= (int v4r) {if(this->x1>=v4r&&this->y1>=v4r && this->x2<=v4r&&this->y2<=v4r){return true;}else return false;};
};

struct v4f
{
	float x1,y1,x2,y2;
	v4f(){};
	v4f      (float x1,float y1,float x2,float y2){this->x1 = x1;this->y1 = y1;this->x2 = x2;this->y2 = y2;};
	void set(float x1,float y1,float x2,float y2){this->x1 = x1;this->y1 = y1;this->x2 = x2;this->y2 = y2;};

	v4f operator = (v4f v4fr) {this->x1=v4fr.x1;this->y1=v4fr.y1; this->x2=v4fr.x2;this->y2=v4fr.y2; return v4fr;};
	v4f operator + (v4f v4fr) {v4f sum;sum.x1 = this->x1+v4fr.x1;sum.y1 = this->y1+v4fr.y1; sum.x2 = this->x2+v4fr.x2;sum.y2 = this->y2+v4fr.y2;return sum;};
	v4f operator - (v4f v4fr) {v4f sum;sum.x1 = this->x1-v4fr.x1;sum.y1 = this->y1-v4fr.y1; sum.x2 = this->x2-v4fr.x2;sum.y2 = this->y2-v4fr.y2;return sum;};
	v4f operator * (v4f v4fr) {v4f sum;sum.x1 = this->x1*v4fr.x1;sum.y1 = this->y1*v4fr.y1; sum.x2 = this->x2*v4fr.x2;sum.y2 = this->y2*v4fr.y2;return sum;};
	v4f operator / (v4f v4fr) {v4f sum;sum.x1 = this->x1/v4fr.x1;sum.y1 = this->y1/v4fr.y1; sum.x2 = this->x2/v4fr.x2;sum.y2 = this->y2/v4fr.y2;return sum;};

	v4f operator () (float x1,float y1,float x2,float y2) {this->x1 = x1;this->y1 = y1;this->x2 = x2;this->y2 = y2;return(v4f(x1,y1,x2,y2));}; //
	v4f operator () (v4f v4r) {this->x1=v4r.x1;this->y1=v4r.y1; this->x2=v4r.x2;this->y2=v4r.y2; return v4r;}; //

	v4f operator = (float v4fr) {this->x1=v4fr;this->y1=v4fr; this->x2=v4fr;this->y2=v4fr; return v4f(this->x1,this->y1,this->x2,this->y2);};
	v4f operator + (float v4fr) {v4f sum;sum.x1 = this->x1+v4fr;sum.y1 = this->y1+v4fr; sum.x2 = this->x2+v4fr;sum.y2 = this->y2+v4fr;return sum;};
	v4f operator - (float v4fr) {v4f sum;sum.x1 = this->x1-v4fr;sum.y1 = this->y1-v4fr; sum.x2 = this->x2-v4fr;sum.y2 = this->y2-v4fr;return sum;};
	v4f operator * (float v4fr) {v4f sum;sum.x1 = this->x1*v4fr;sum.y1 = this->y1*v4fr; sum.x2 = this->x2*v4fr;sum.y2 = this->y2*v4fr;return sum;};
	v4f operator / (float v4fr) {v4f sum;sum.x1 = this->x1/v4fr;sum.y1 = this->y1/v4fr; sum.x2 = this->x2/v4fr;sum.y2 = this->y2/v4fr;return sum;};

	bool operator != (v4f v4fr) {if(this->x1!=v4fr.x1&&this->y1!=v4fr.y1 && this->x2!=v4fr.x2&&this->y2!=v4fr.y2){return true;}else return false;};

	bool operator == (v4f v4fr) {if(this->x1==v4fr.x1&&this->y1==v4fr.y1 && this->x2==v4fr.x2&&this->y2==v4fr.y2){return true;}else return false;};
	bool operator <  (v4f v4fr) {if(this->x1< v4fr.x1&&this->y1< v4fr.y1 && this->x2< v4fr.x2&&this->y2< v4fr.y2){return true;}else return false;};
	bool operator >  (v4f v4fr) {if(this->x1> v4fr.x1&&this->y1> v4fr.y1 && this->x2> v4fr.x2&&this->y2> v4fr.y2){return true;}else return false;};
	bool operator <= (v4f v4fr) {if(this->x1<=v4fr.x1&&this->y1<=v4fr.y1 && this->x2<=v4fr.x2&&this->y2<=v4fr.y2){return true;}else return false;};
	bool operator >= (v4f v4fr) {if(this->x1>=v4fr.x1&&this->y1>=v4fr.y1 && this->x2<=v4fr.x2&&this->y2<=v4fr.y2){return true;}else return false;};

	bool operator != (float v4fr) {if(this->x1!=v4fr&&this->y1!=v4fr && this->x2!=v4fr&&this->y2!=v4fr){return true;}else return false;};

	bool operator == (float v4fr) {if(this->x1==v4fr&&this->y1==v4fr && this->x2==v4fr&&this->y2==v4fr){return true;}else return false;};
	bool operator <  (float v4fr) {if(this->x1< v4fr&&this->y1< v4fr && this->x2< v4fr&&this->y2< v4fr){return true;}else return false;};
	bool operator >  (float v4fr) {if(this->x1> v4fr&&this->y1> v4fr && this->x2> v4fr&&this->y2> v4fr){return true;}else return false;};
	bool operator <= (float v4fr) {if(this->x1<=v4fr&&this->y1<=v4fr && this->x2<=v4fr&&this->y2<=v4fr){return true;}else return false;};
	bool operator >= (float v4fr) {if(this->x1>=v4fr&&this->y1>=v4fr && this->x2<=v4fr&&this->y2<=v4fr){return true;}else return false;};
};

#endif