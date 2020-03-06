	double pi = 3.141592654;
	double cm = 1;

	int width = 600*cm;
	int height = 1000*cm;

	double R1 = 177*cm;
	double R2 = 180*cm;
	double R3 = 185*cm;

	double PMT_r1 = 12*cm;
	double PMT_r2 = 8*cm;
	double PMT_W = 6*cm;
	double PMT_H = 15*cm;
	double PMT_R = 200*cm;


	double theta1 = 10;
	double theta2 = asin(((R1*sin(theta1/180*pi) + R2-R1))/R2)/pi*180;
	double theta3 = asin(((R1*sin(theta1/180*pi) + R3-R1))/R3)/pi*180;
	double Cx = width/2.0;
	double Cy = Cx;

	double chimney_H1 = 100*cm;
	double chimney_H2 = 50*cm;

	double chimney_W1 = R1*(20./180*pi);
	double chimney_Y1 = Cy+R1*cos(10./180*pi); 

	double chimney_Y2 = Cy+R2*cos(theta2/180*pi); 
	double chimney_W2 = chimney_W1 + 6*cm;

	double chimney_Y3 = Cy+R3*cos(theta3/180*pi); 
	double chimney_W3 = chimney_W2 + 10*cm;
	double chimney_H3 = chimney_H2 + chimney_Y2 - chimney_Y3;

	double house_Y = chimney_Y1 + chimney_H1;
	double house_H = 200*cm;
	double house_W = 320*cm + chimney_W1;

	double bridge_Y = house_Y*2./5 + chimney_Y1*3./5; 
	double bridge_W = 200*cm;

	double house_chim_W = 10*cm;
	double house_chimney_H = 10*cm;
	double house_chim_Y = house_Y + house_H;

	double ACU_H = 85*cm;
	double ACU_W = 130*cm;
	double ACU_Y = house_chim_Y + house_chimney_H;
	double ACU_shift = 45*cm;

	double anchor1 = 48; // unit: degree
	double anchor2 = 78; // unit: degree
	double anchor_r = 8*cm;
	double R_anchor = R1 - anchor_r;

	double anchor1_point_X = Cx + R1*sin(anchor1/180*pi);
	double anchor1_point_Y = Cy + R1*cos(anchor1/180*pi);
	double anchor2_point_X = Cx - R1*sin(anchor2/180*pi);
	double anchor2_point_Y = Cy + R1*cos(anchor2/180*pi);

	double ROV_W = 30*cm;
	double ROV_H = 50*cm;
	double ROV_R = 20*cm;
	double ROV_X = Cx + 30*cm;
	double ROV_Y = Cy - 80*cm;
	double ROV_theta = 2*asin(ROV_W/2/ROV_R)*180/pi;
	double ROV_bot_Cx = ROV_X + ROV_W/2;
	double ROV_bot_Cy = ROV_Y + sqrt(ROV_R*ROV_R - ROV_W/2*ROV_W/2);
	double spool_W = 32*cm;
	double spool_H = 20*cm;
	double spool_L = 40*cm;




