#include "parameters.h"
#include "color.h"
//void draw_spool(double x,double y,double spool_W,double spool_H,double spool_L,int dir){
void draw_spool(double x,double y,int dir){

	int colorid = Spool_Color;
	if(dir == 0){ // direction is right
		TBox* spool_1 = new TBox(x,y,x+spool_W,y+spool_H);
		spool_1->SetLineWidth(3);
		spool_1->SetFillColor(colorid);
		spool_1->Draw();
		TLine *spool_2 = new TLine(x+spool_W,y+spool_H/2,x+spool_L,y+spool_H/2);
		spool_2->SetLineWidth(5);
		spool_2->SetLineColor(colorid);
		spool_2->Draw();
		TLatex* spool_tag = new TLatex(x,y+spool_H/4,"spool");
		spool_tag->SetTextSize(0.02);
		spool_tag->Draw();
	}
	else{	// directrion is left
		TBox* spool_1 = new TBox(x,y,x-spool_W,y+spool_H);
		spool_1->SetLineWidth(3);
		spool_1->SetFillColor(colorid);
		spool_1->Draw();
		TLine *spool_2 = new TLine(x-spool_W,y+spool_H/2,x-spool_L,y+spool_H/2);
		spool_2->SetLineColor(colorid);
		spool_2->SetLineWidth(5);
		spool_2->Draw();
		TLatex* spool_tag = new TLatex(x-spool_W,y+spool_H/4,"spool");
		spool_tag->SetTextSize(0.02);
		spool_tag->Draw();
	}

}

void draw_PMT(double theta){

	double pi = 3.141592654;
	double X = Cx + PMT_R*sin(theta/180.0*pi);
	double Y = Cx + PMT_R*cos(theta/180.0*pi);

	TEllipse* PMT = new TEllipse(X,Y,PMT_r1,PMT_r2,0,360,-theta);
	PMT->SetFillColor(PMT_Color);
	PMT->SetLineColor(PMT_Color);
	PMT->Draw();

	TLine* PMT_Line1 = new TLine(X - PMT_W/2*cos(theta/180*pi), Y + PMT_W/2*sin(theta/180*pi), X - PMT_W/2*cos(theta/180*pi) + PMT_H*sin(theta/180*pi), Y + PMT_W/2*sin(theta/180*pi) + PMT_H*cos(theta/180*pi));
	TLine* PMT_Line2 = new TLine(X - PMT_W/2*cos(theta/180*pi) + PMT_H*sin(theta/180*pi), Y + PMT_W/2*sin(theta/180*pi) + PMT_H*cos(theta/180*pi), X + PMT_W/2*cos(theta/180*pi) + PMT_H*sin(theta/180*pi), Y - PMT_W/2*sin(theta/180*pi) + PMT_H*cos(theta/180*pi));
	TLine* PMT_Line3 = new TLine(X + PMT_W/2*cos(theta/180*pi) + PMT_H*sin(theta/180*pi), Y - PMT_W/2*sin(theta/180*pi) + PMT_H*cos(theta/180*pi),X + PMT_W/2*cos(theta/180*pi),Y - PMT_W/2*sin(theta/180*pi));

	PMT_Line1->SetLineWidth(6);
	PMT_Line2->SetLineWidth(6);
	PMT_Line3->SetLineWidth(6);

	PMT_Line1->SetLineColor(PMT_Color);
	PMT_Line2->SetLineColor(PMT_Color);
	PMT_Line3->SetLineColor(PMT_Color);

	PMT_Line1->Draw();
	PMT_Line2->Draw();
	PMT_Line3->Draw();
}

void draw(){

	//--------------All paramters-----------------
	//double pi = 3.141592654;
	//double cm = 1;

	//int width = 600*cm;
	//int height = 1000*cm;

	//double R1 = 177*cm;
	//double R2 = 180*cm;
	//double R3 = 185*cm;

	//double PMT_r1 = 12*cm;
	//double PMT_r2 = 8*cm;
	//double PMT_W = 6*cm;
	//double PMT_H = 15*cm;
	//double PMT_R = 200*cm;


	//double theta1 = 10;
	//double theta2 = asin(((R1*sin(theta1/180*pi) + R2-R1))/R2)/pi*180;
	//double theta3 = asin(((R1*sin(theta1/180*pi) + R3-R1))/R3)/pi*180;
	//double Cx = width/2.0;
	//double Cy = Cx;

	//double chimney_H1 = 100*cm;
	//double chimney_H2 = 50*cm;

	//double chimney_W1 = R1*(20./180*pi);
	//double chimney_Y1 = Cy+R1*cos(10./180*pi); 

	//double chimney_Y2 = Cy+R2*cos(theta2/180*pi); 
	//double chimney_W2 = chimney_W1 + 6*cm;

	//double chimney_Y3 = Cy+R3*cos(theta3/180*pi); 
	//double chimney_W3 = chimney_W2 + 10*cm;
	//double chimney_H3 = chimney_H2 + chimney_Y2 - chimney_Y3;

	//double house_Y = chimney_Y1 + chimney_H1;
	//double house_H = 150*cm;
	//double house_W = 320*cm + chimney_W1;

	//double bridge_Y = house_Y/3 + chimney_Y1*2.0/3; 
	//double bridge_W = 200*cm;

	//double house_chim_W = 10*cm;
	//double house_chimney_H = 10*cm;
	//double house_chim_Y = house_Y + house_H;

	//double ACU_H = 85*cm;
	//double ACU_W = 130*cm;
	//double ACU_Y = house_chim_Y + house_chimney_H;
	//double ACU_shift = 45*cm;

	//double anchor1 = 48; // unit: degree
	//double anchor2 = 78; // unit: degree
	//double anchor_r = 10*cm;
	//double R_anchor = R1 - anchor_r;

	//double anchor1_point_X = Cx + R1*sin(anchor1/180*pi);
	//double anchor1_point_Y = Cy + R1*cos(anchor1/180*pi);
	//double anchor2_point_X = Cx - R1*sin(anchor2/180*pi);
	//double anchor2_point_Y = Cy + R1*cos(anchor2/180*pi);

	//double ROV_W = 30*cm;
	//double ROV_H = 50*cm;
	//double ROV_R = 20*cm;
	//double ROV_X = Cx + 30*cm;
	//double ROV_Y = Cy - 80*cm;
	//double ROV_theta = 2*asin(ROV_W/2/ROV_R)*180/pi;
	//double ROV_bot_Cx = ROV_X + ROV_W/2;
	//double ROV_bot_Cy = ROV_Y + sqrt(ROV_R*ROV_R - ROV_W/2*ROV_W/2);
	//double spool_W = 32*cm;
	//double spool_H = 20*cm;
	//double spool_L = 40*cm;

//--------------------------------------------------------------------
	TCanvas *c1 = new TCanvas("c1","",width,height);
	c1->Range(0,0,width,height);

//------------------------CD-----------------------------------------------
	TCrown *cr1 = new TCrown(Cx,Cy,R1,R1,100,440);	
	TCrown *cr2 = new TCrown(Cx,Cy,R2,R2,90 + theta2,450 - theta2);	
	TCrown *cr3 = new TCrown(Cx,Cy,R3,R3,90 + theta3,450 - theta3);	

	cr1->SetLineColor(Acrylic_Color);
	cr2->SetLineColor(GT_Color);
	cr3->SetLineColor(GT_Color);

	cr1->SetLineWidth(4);
	cr2->SetLineWidth(4);
	cr3->SetLineWidth(4);
	cr1->Draw();
	cr2->Draw();
	cr3->Draw();

//-----------------------Chimney--------------------------------

	TLine *l1 = new TLine(Cx - chimney_W1/2,chimney_Y1,Cy - chimney_W1/2,chimney_Y1 + chimney_H1);
	TLine *l2 = new TLine(Cx + chimney_W1/2,chimney_Y1,Cy + chimney_W1/2,chimney_Y1 + chimney_H1);

	TLine *l3 = new TLine(Cx - chimney_W2/2,chimney_Y2,Cy - chimney_W2/2,chimney_Y2 + chimney_H2);
	TLine *l4 = new TLine(Cx + chimney_W2/2,chimney_Y2,Cy + chimney_W2/2,chimney_Y2 + chimney_H2);
	TLine *l5 = new TLine(Cx - chimney_W3/2,chimney_Y3,Cy - chimney_W3/2,chimney_Y3 + chimney_H3);
	TLine *l6 = new TLine(Cx + chimney_W3/2,chimney_Y3,Cy + chimney_W3/2,chimney_Y3 + chimney_H3);

	l3->SetLineColor(Acrylic_Color);
	l4->SetLineColor(Acrylic_Color);

	l3->SetLineColor(GT_Color);
	l4->SetLineColor(GT_Color);
	l5->SetLineColor(GT_Color);
	l6->SetLineColor(GT_Color);

	l1->SetLineWidth(4);
	l1->Draw();
	
	l2->SetLineWidth(4);
	l2->Draw();
	
	l3->SetLineWidth(4);
	l3->Draw();
	
	l4->SetLineWidth(4);
	l4->Draw();
	
	l5->SetLineWidth(4);
	l5->Draw();
	
	l6->SetLineWidth(4);
	l6->Draw();

//---------------------------calibration house --------------------------------------------
///
	TLine *house_bot_l = new TLine(Cx - chimney_W1/2,house_Y,Cx - house_W/2,house_Y);
	TLine *house_bot_r = new TLine(Cx + chimney_W1/2,house_Y,Cx + house_W/2,house_Y);
	TLine* house_mid_l = new TLine(Cx - house_W/2,house_Y,Cx - house_W/2,house_Y + house_H);
	TLine* house_mid_r = new TLine(Cx + house_W/2,house_Y,Cx + house_W/2,house_Y + house_H);
	TLine* house_top_l = new TLine(Cx - house_W/2,house_Y + house_H,Cx - house_chim_W/2,house_Y + house_H);
	TLine* house_top_r = new TLine(Cx + house_W/2,house_Y + house_H,Cx + house_chim_W/2,house_Y + house_H);

	house_bot_l->SetLineColor(House_Color);
	house_bot_r->SetLineColor(House_Color);
	house_mid_l->SetLineColor(House_Color);
	house_mid_r->SetLineColor(House_Color);
	house_top_l->SetLineColor(House_Color);
	house_top_r->SetLineColor(House_Color);

	house_bot_l->SetLineWidth(3);
	house_bot_l->Draw();
	
	house_bot_r->SetLineWidth(3);
	house_bot_r->Draw();

	house_mid_l->SetLineWidth(3);
	house_mid_l->Draw();
		
	house_mid_r->SetLineWidth(3);
	house_mid_r->Draw();

	house_top_l->SetLineWidth(3);
	house_top_l->Draw();

	house_top_r->SetLineWidth(3);
	house_top_r->Draw();

//-----------------house chimney----------------

	TLine* house_chim_l = new TLine(Cx - house_chim_W/2,house_chim_Y,Cx - house_chim_W/2,ACU_Y);
	TLine* house_chim_r = new TLine(Cx + house_chim_W/2,house_chim_Y,Cx + house_chim_W/2,ACU_Y);

	house_chim_l->SetLineWidth(3);
	house_chim_r->SetLineWidth(3);

	house_chim_l->Draw();
	house_chim_r->Draw();

//---------------ROV guide rail-------------------------
//

	double Guide_rail_L = house_W/4;
	double Guide_rail_Y = 0.95*house_H + house_Y;
	TLine *guide_rail = new TLine(Cx - Guide_rail_L/2,Guide_rail_Y,Cx + Guide_rail_L/2,Guide_rail_Y);
	guide_rail->SetLineWidth(4);
	guide_rail->SetLineColor(ROV_Guide_Rail_Color);
	guide_rail->Draw();
			
//-----------------ACU----------------------------------

	TLine* ACU_bot_l = new TLine(Cx - house_chim_W/2,ACU_Y,Cx - ACU_W/2 - ACU_shift,ACU_Y);
	TLine* ACU_bot_r = new TLine(Cx + house_chim_W/2,ACU_Y,Cx + ACU_W/2 - ACU_shift,ACU_Y);
	TLine* ACU_mid_l = new TLine(Cx - ACU_W/2 - ACU_shift,ACU_Y,Cx - ACU_W/2 - ACU_shift,ACU_Y + ACU_H);
	TLine* ACU_mid_r = new TLine(Cx + ACU_W/2 - ACU_shift,ACU_Y,Cx + ACU_W/2 - ACU_shift,ACU_Y + ACU_H);
	TLine* ACU_top   = new TLine(Cx - ACU_W/2 - ACU_shift,ACU_Y + ACU_H,Cx + ACU_W/2 - ACU_shift,ACU_Y + ACU_H);

	ACU_bot_l->SetLineColor(ACU_Box_Color);
	ACU_bot_r->SetLineColor(ACU_Box_Color);
	ACU_mid_l->SetLineColor(ACU_Box_Color);
	ACU_mid_r->SetLineColor(ACU_Box_Color);
	ACU_top  ->SetLineColor(ACU_Box_Color);

	ACU_bot_l->SetLineWidth(3);
	ACU_bot_r->SetLineWidth(3);
	ACU_mid_l->SetLineWidth(3);
	ACU_mid_r->SetLineWidth(3);
	ACU_top->SetLineWidth(3);

	ACU_bot_l->Draw();
	ACU_bot_r->Draw();
	ACU_mid_l->Draw();
	ACU_mid_r->Draw();
	ACU_top->Draw();

//------------------anchors------------------------------

	TArc *arc1 = new TArc(Cx+R_anchor*sin(anchor1/180*pi),Cx+R_anchor*cos(anchor1/180*pi),anchor_r);
	arc1->SetLineColor(kBlue);
	arc1->SetFillColor(kBlue);
	arc1->Draw();

	TArc *arc2 = new TArc(Cx-R_anchor*sin(anchor2/180*pi),Cx+R_anchor*cos(anchor2/180*pi),anchor_r);
	arc2->SetLineColor(kBlue);
	arc2->SetFillColor(kBlue);
	arc2->Draw();
//--------------------bridge--------------------------------

	TLine* bridge_l = new TLine(Cx-chimney_W3/2,bridge_Y,Cx-bridge_W,bridge_Y);
	TLine* bridge_r = new TLine(Cx+chimney_W3/2,bridge_Y,Cx+bridge_W,bridge_Y);

	bridge_l->SetLineWidth(3);
	bridge_r->SetLineWidth(3);
	bridge_l->Draw();
	bridge_r->Draw();

//------------------------AURORA---------------------
	
	//---------------AURORA Box---------------------
	double PMT_PSR_W = 60*cm;
	double PMT_PSR_H = 40*cm;

	TBox* PMT_PSR = new TBox(Cx - bridge_W, bridge_Y + 3*cm,Cx - bridge_W + PMT_PSR_W, bridge_Y + 3*cm + PMT_PSR_H); // PMT Power Supply Room
	PMT_PSR->SetFillColor(AURORA_Color);
	PMT_PSR->Draw();

	TLatex *PMT_PSR_tag1 = new TLatex(Cx - bridge_W+3*cm, bridge_Y + 3*cm+ PMT_PSR_H*0.66,"PMT Power");
	PMT_PSR_tag1->SetTextSize(0.015);
	PMT_PSR_tag1->Draw();

	TLatex *PMT_PSR_tag2 = new TLatex(Cx - bridge_W+3*cm, bridge_Y + 3*cm+ PMT_PSR_H*0.33,"Supply Room");
	PMT_PSR_tag2->SetTextSize(0.015);
	PMT_PSR_tag2->Draw();

	//-------------------------Led-------------------------------------

	double led_H = 6*cm;
	double led_L = 20*cm;

	double led1_X = Cx - PMT_R*sin(85./180*pi);
	double led1_Y = Cy - PMT_R*cos(85./180*pi);

	TBox* led1_mid = new TBox(led1_X-(led_L-led_H)/2,led1_Y - led_H/2,led1_X+(led_L-led_H)/2,led1_Y + led_H/2);
	led1_mid->SetFillColor(Led_Color);
	led1_mid->Draw();
	TArc* led1_left = new TArc(led1_X-(led_L-led_H)/2,led1_Y,led_H/2);
	led1_left->SetFillColor(Led_Color);
	led1_left->SetLineColor(Led_Color);
	led1_left->Draw();
	TArc* led1_right = new TArc(led1_X+(led_L-led_H)/2,led1_Y,led_H/2);
	led1_right->SetFillColor(Led_Color);
	led1_right->SetLineColor(Led_Color);
	led1_right->Draw();

	double led2_X = Cx - PMT_R*sin(95./180*pi);
	double led2_Y = Cy - PMT_R*cos(95./180*pi);
	TBox* led2_mid = new TBox(led2_X-(led_L-led_H)/2,led2_Y - led_H/2,led2_X+(led_L-led_H)/2,led2_Y + led_H/2);
	led2_mid->SetFillColor(Led_Color);
	led2_mid->SetLineColor(Led_Color);
	led2_mid->Draw();
	TArc* led2_left = new TArc(led2_X-(led_L-led_H)/2,led2_Y,led_H/2);
	led2_left->SetFillColor(Led_Color);
	led2_left->SetLineColor(Led_Color);
	led2_left->Draw();
	TArc* led2_right = new TArc(led2_X+(led_L-led_H)/2,led2_Y,led_H/2);
	led2_right->SetFillColor(Led_Color);
	led2_right->SetLineColor(Led_Color);
	led2_right->Draw();

	double led3_X = Cx - PMT_R*sin(155./180*pi);
	double led3_Y = Cy - PMT_R*cos(155./180*pi);
	TBox* led3_mid = new TBox(led3_X - led_H/2,led3_Y-(led_L-led_H)/2,led3_X + led_H/2, led3_Y+(led_L-led_H)/2);
	led3_mid->SetFillColor(Led_Color);
	led3_mid->Draw();
	TArc* led3_top = new TArc(led3_X,led3_Y+(led_L-led_H)/2,led_H/2);
	led3_top->SetFillColor(Led_Color);
	led3_top->SetLineColor(Led_Color);
	led3_top->Draw();
	TArc* led3_bot = new TArc(led3_X,led3_Y-(led_L-led_H)/2,led_H/2);
	led3_bot->SetFillColor(Led_Color);
	led3_bot->SetLineColor(Led_Color);
	led3_bot->Draw();

	double led4_X = Cx - PMT_R*sin(165./180*pi);
	double led4_Y = Cy - PMT_R*cos(165./180*pi);
	TBox* led4_mid = new TBox(led4_X - led_H/2,led4_Y-(led_L-led_H)/2,led4_X + led_H/2, led4_Y+(led_L-led_H)/2);
	led4_mid->SetFillColor(Led_Color);
	led4_mid->SetLineColor(Led_Color);
	led4_mid->Draw();
	TArc* led4_top = new TArc(led4_X,led4_Y+(led_L-led_H)/2,led_H/2);
	led4_top->SetFillColor(Led_Color);
	led4_top->SetLineColor(Led_Color);
	led4_top->Draw();
	TArc* led4_bot = new TArc(led4_X,led4_Y-(led_L-led_H)/2,led_H/2);
	led4_bot->SetFillColor(Led_Color);
	led4_bot->SetLineColor(Led_Color);
	led4_bot->Draw();

//-----------------------------ROV-------------------

	TBox *ROV_top = new TBox(ROV_X, ROV_Y, ROV_X+ROV_W ,ROV_Y+ROV_H);
	ROV_top->SetFillColor(kBlue);
	ROV_top->Draw();

	TArc *ROV_bot = new TArc(ROV_bot_Cx,ROV_bot_Cy,ROV_R,270 - ROV_theta/2,270+ROV_theta/2);
	ROV_bot->SetLineColor(kBlue);
	ROV_bot->SetFillColor(kBlue);
	ROV_bot->Draw();

	double ROV_caple_l = 25*cm;
	TLine *ROV_caple = new TLine(ROV_bot_Cx,ROV_bot_Cy - ROV_R, ROV_bot_Cx,ROV_Y-ROV_caple_l);
	ROV_caple->SetLineWidth(4);;
	ROV_caple->Draw();

//-----------------------------Spool--------------------

	//---------------ACU spools-----------------------
	double spool_X1 = Cx - spool_L;
	double spool_Y1 = ACU_Y + 50*cm;
	draw_spool(spool_X1,spool_Y1,0);

	double spool_X2 = Cx - spool_L - 12*cm;
	double spool_Y2 = spool_Y1;
	draw_spool(spool_X2,spool_Y2,1);

	//------------------CLS spools--------------------
	
	double spool_X3 = Cx - house_W/2*0.85;
	double spool_Y3 = house_Y + house_H*0.6;
	draw_spool(spool_X3,spool_Y3,0);

	double spool_X4 = Cx - house_W/2*0.65;
	double spool_Y4 = house_Y + house_H*0.4;
	draw_spool(spool_X4,spool_Y4,0);

	double spool_X5 = Cx + house_W/2*0.85;
	double spool_Y5 = house_Y + house_H*0.6;
	draw_spool(spool_X5,spool_Y5,1);

	double spool_X6 = Cx + house_W/2*0.65;
	double spool_Y6 = house_Y + house_H*0.4;
	draw_spool(spool_X6,spool_Y6,1);

//-------------------Guide Tube Spools-------------------------------
//
	double spool_X7 = Cx - house_W/2*0.65;
	double spool_Y7 = house_Y*0.4 + bridge_Y*0.6;
	draw_spool(spool_X7,spool_Y7,0);

	double spool_X8 = Cx + house_W/2*0.65;
	double spool_Y8 = house_Y*0.4 + bridge_Y*0.6;
	draw_spool(spool_X8,spool_Y8,1);

//--------------------PMTs--------------------------------------

	//draw_PMT(20,PMT_r1,PMT_r2, PMT_W, PMT_H, PMT_R);
	for(int i=0;i<33;i++){
		draw_PMT(i*10+20);
	}

//-------------------------Source storage------------------------

	double source_storage_D = 2*chimney_W1;
	double source_storage_Y = (house_Y + spool_Y3)/2;
	TLine *source_storage_line = new TLine(Cx - source_storage_D/2,source_storage_Y,Cx + source_storage_D/2,source_storage_Y);
	source_storage_line->SetLineWidth(4);
	source_storage_line->Draw();

	double storage_cable_L = (source_storage_Y - house_Y)*2./3;
	TLine* storage_S1_cable = new TLine(Cx - source_storage_D/2,source_storage_Y,Cx - source_storage_D/2,source_storage_Y - storage_cable_L);
	storage_S1_cable->SetLineWidth(4);
	storage_S1_cable->Draw();

	TLine* storage_S2_cable = new TLine(Cx - source_storage_D*3/8 ,source_storage_Y,Cx - source_storage_D*3/8,source_storage_Y - storage_cable_L);
	storage_S2_cable->SetLineWidth(4);
	storage_S2_cable->Draw();

	TLine* storage_S3_cable = new TLine(Cx + source_storage_D/2,  source_storage_Y,Cx + source_storage_D/2,source_storage_Y - storage_cable_L);
	storage_S3_cable->SetLineWidth(4);
	storage_S3_cable->Draw();

	TLine* storage_S4_cable = new TLine(Cx + source_storage_D*3/8 ,source_storage_Y,Cx + source_storage_D*3/8,source_storage_Y - storage_cable_L);
	storage_S4_cable->SetLineWidth(4);
	storage_S4_cable->Draw();


        TArc *storage_S1 = new TArc(Cx - source_storage_D/2 ,source_storage_Y - storage_cable_L ,R_source);
        storage_S1->SetLineColor(kRed);
        storage_S1->SetFillColor(kRed);
        storage_S1->Draw();

        TArc *storage_S2 = new TArc(Cx - source_storage_D*3/8,source_storage_Y - storage_cable_L,R_source);
        storage_S2->SetLineColor(kRed);
        storage_S2->SetFillColor(kRed);
        storage_S2->Draw();

        TArc *storage_S3 = new TArc(Cx + source_storage_D/2 ,source_storage_Y - storage_cable_L,R_source);
        storage_S3->SetLineColor(kRed);
        storage_S3->SetFillColor(kRed);
        storage_S3->Draw();

        TArc *storage_S4 = new TArc(Cx + source_storage_D*3/8,source_storage_Y - storage_cable_L,R_source);
        storage_S4->SetLineColor(kRed);
        storage_S4->SetFillColor(kRed);
        storage_S4->Draw();

//----------------------------------------------------------

	TLine *sp1_line_sp2 = new TLine(spool_X1,spool_Y1 + spool_H/2,spool_X2,spool_Y1 + spool_H/2);
	sp1_line_sp2->SetLineWidth(4);
	sp1_line_sp2->Draw();

	double length_spool2table = 15*cm;
	TLine *sp_line_table = new TLine((spool_X1+spool_X2)/2,spool_Y1 + spool_H/2,(spool_X1+spool_X2)/2,spool_Y1 + spool_H/2 - length_spool2table);
	sp_line_table->SetLineWidth(6);
	sp_line_table->Draw();

	double TurnTable_W = ACU_W/3;
	double TurnTable_H = ACU_H/2;
	double TurnTable_X = (spool_X1 + spool_X2)/2 - TurnTable_W/2;
	double TurnTable_Y = spool_Y1 + spool_H/2 - length_spool2table - TurnTable_H;
	TBox* turntable = new TBox(TurnTable_X,TurnTable_Y,TurnTable_X+TurnTable_W,TurnTable_Y+TurnTable_H);
	turntable->SetFillColor(TurnTable_Color);
	turntable->SetLineWidth(4);
	turntable->Draw();

//--------------------------cables-----------------------

	//----------------ACU cables---------------------
	TLine* ACU_cable1 = new TLine(Cx,Cy,Cx,spool_Y1 + spool_H/2);
	ACU_cable1->SetLineWidth(4);
	ACU_cable1->SetLineColor(ACU_Cable_Color);
	ACU_cable1->Draw();

	TLine* ACU_cable2 = new TLine(spool_X2 - spool_L, TurnTable_Y*2/3 + (spool_Y1 + spool_H/2)/3,spool_X2 - spool_L, spool_Y1 + spool_H/2);
	ACU_cable2->SetLineWidth(4);
	ACU_cable2->SetLineColor(ACU_Cable_Color);
	ACU_cable2->Draw();


	//-------------------CLS cables-----------------------

	double CLS_S1_X = Cx - R1*0.5;
	double CLS_S1_Y = Cy - R1*0.5;
	
	double CLS_S2_X = Cx + R1*0.6;
	double CLS_S2_Y = Cy - R1*0.1;
	
	double central_offset = chimney_W1/2*0.5;;
	double side_offset = chimney_W1/2*0.8; 

	TLine* spool3_cable1 = new TLine(spool_X3 + spool_L, spool_Y3 + spool_H/2, Cx - central_offset, spool_Y3+spool_H/2);
	spool3_cable1->SetLineWidth(4);
	spool3_cable1->SetLineColor(CLS_Cable1_Color);
	spool3_cable1->Draw();

	TLine* spool3_cable2 = new TLine(Cx - central_offset, spool_Y3+spool_H/2,Cx - central_offset, chimney_Y1);
	spool3_cable2->SetLineWidth(4);
	spool3_cable2->SetLineColor(CLS_Cable1_Color);
	spool3_cable2->Draw();

	TLine* spool3_cable3 = new TLine(Cx - central_offset, chimney_Y1,CLS_S1_X,CLS_S1_Y);
	spool3_cable3->SetLineWidth(4);
	spool3_cable3->SetLineColor(CLS_Cable1_Color);
	spool3_cable3->Draw();
	
	TLine* spool4_cable1 = new TLine(spool_X4 + spool_L, spool_Y4 + spool_H/2, Cx - side_offset, spool_Y4 + spool_H/2);
	spool4_cable1->SetLineWidth(4);
	spool4_cable1->SetLineColor(CLS_Cable2_Color);
	spool4_cable1->Draw();

	TLine* spool4_cable2 = new TLine(Cx - side_offset, spool_Y4 + spool_H/2, Cx - side_offset, house_Y);
	spool4_cable2->SetLineWidth(4);
	spool4_cable2->SetLineColor(CLS_Cable2_Color);
	spool4_cable2->Draw();

	TLine* spool4_cable3 = new TLine(Cx - side_offset, house_Y,Cx - side_offset, chimney_Y1);
	spool4_cable3->SetLineWidth(4);
	spool4_cable3->SetLineColor(CLS_Cable2_Color);
	spool4_cable3->Draw();

	TLine* spool4_cable4 = new TLine(Cx - side_offset, chimney_Y1,anchor2_point_X,anchor2_point_Y);
	spool4_cable4->SetLineWidth(4);
	spool4_cable4->SetLineColor(CLS_Cable2_Color);
	spool4_cable4->Draw();

	TLine* spool4_cable5 = new TLine(anchor2_point_X,anchor2_point_Y,CLS_S1_X,CLS_S1_Y);
	spool4_cable5->SetLineWidth(4);
	spool4_cable5->SetLineColor(CLS_Cable2_Color);
	spool4_cable5->Draw();


	TLine* spool5_cable1 = new TLine(spool_X5 - spool_L, spool_Y5 + spool_H/2, Cx + central_offset, spool_Y5+spool_H/2);
	spool5_cable1->SetLineWidth(4);
	spool5_cable1->SetLineColor(CLS_Cable1_Color);
	spool5_cable1->Draw();

	TLine* spool5_cable2 = new TLine(Cx + central_offset, spool_Y5+spool_H/2,Cx + central_offset, chimney_Y1);
	spool5_cable2->SetLineWidth(4);
	spool5_cable2->SetLineColor(CLS_Cable1_Color);
	spool5_cable2->Draw();

	TLine* spool5_cable3 = new TLine(Cx + central_offset, chimney_Y1,CLS_S2_X,CLS_S2_Y);
	spool5_cable3->SetLineWidth(4);
	spool5_cable3->SetLineColor(CLS_Cable1_Color);
	spool5_cable3->Draw();
	
	TLine* spool6_cable1 = new TLine(spool_X6 - spool_L, spool_Y6 + spool_H/2, Cx + side_offset, spool_Y6 + spool_H/2);
	spool6_cable1->SetLineWidth(4);
	spool6_cable1->SetLineColor(CLS_Cable2_Color);
	spool6_cable1->Draw();

	TLine* spool6_cable2 = new TLine(Cx + side_offset, spool_Y6 + spool_H/2, Cx + side_offset, house_Y);
	spool6_cable2->SetLineWidth(4);
	spool6_cable2->SetLineColor(CLS_Cable2_Color);
	spool6_cable2->Draw();

	TLine* spool6_cable3 = new TLine(Cx + side_offset, house_Y,Cx + side_offset, chimney_Y1);
	spool6_cable3->SetLineWidth(4);
	spool6_cable3->SetLineColor(CLS_Cable2_Color);
	spool6_cable3->Draw();

	TLine* spool6_cable4 = new TLine(Cx + side_offset, chimney_Y1,anchor1_point_X,anchor1_point_Y);
	spool6_cable4->SetLineWidth(4);
	spool6_cable4->SetLineColor(CLS_Cable2_Color);
	spool6_cable4->Draw();

	TLine* spool6_cable5 = new TLine(anchor1_point_X,anchor1_point_Y,CLS_S2_X,CLS_S2_Y);
	spool6_cable5->SetLineWidth(4);
	spool6_cable5->SetLineColor(CLS_Cable2_Color);
	spool6_cable5->Draw();

	//------------------ROV cables-------------------

	double ROV_shift = 7*cm;
	TLine* ROV_cable1 = new TLine(Cx+ROV_shift,Guide_rail_Y,Cx+ROV_shift,chimney_Y1);
	ROV_cable1->SetLineWidth(4);
	ROV_cable1->SetLineColor(ROV_Cable_Color);
	ROV_cable1->Draw();

	TCurlyLine* ROV_cable2 = new TCurlyLine(Cx+ROV_shift,chimney_Y1,ROV_X+ROV_W/2,ROV_Y+ROV_H,0.04,0.004);
	ROV_cable2->SetLineWidth(4);
	ROV_cable2->SetLineColor(ROV_Cable_Color);
	ROV_cable2->Draw();

	//---------------Guide Tube cables--------------------
	double R4 = (R2+R3)/2;
	double theta4 = (theta2 + theta3)/2;
	TCrown *tube_cur_cable = new TCrown(Cx,Cy,R4,R4,90 + theta4,450 - theta4);
	tube_cur_cable->SetLineWidth(4);
	tube_cur_cable->SetLineColor(GT_Cable_Color);
	tube_cur_cable->Draw();

	TLine* GT_cable1 = new TLine(spool_X7 + spool_L, spool_Y7 + spool_H/2, Cx - (chimney_W2 + chimney_W3)/2/2 ,spool_Y7 + spool_H/2);
	TLine* GT_cable2 = new TLine(Cx - (chimney_W2 + chimney_W3)/2/2 ,spool_Y7 + spool_H/2, Cx - (chimney_W2 + chimney_W3)/2/2, (chimney_Y2 + chimney_Y3)/2);
	TLine* GT_cable3 = new TLine(spool_X8 - spool_L, spool_Y8 + spool_H/2, Cx + (chimney_W2 + chimney_W3)/2/2 ,spool_Y7 + spool_H/2);
	TLine* GT_cable4 = new TLine(Cx + (chimney_W2 + chimney_W3)/2/2 ,spool_Y7 + spool_H/2, Cx + (chimney_W2 + chimney_W3)/2/2, (chimney_Y2 + chimney_Y3)/2);
	GT_cable1->SetLineWidth(4);
	GT_cable2->SetLineWidth(4);
	GT_cable3->SetLineWidth(4);
	GT_cable4->SetLineWidth(4);

	GT_cable1->SetLineColor(GT_Cable_Color);
	GT_cable2->SetLineColor(GT_Cable_Color);
	GT_cable3->SetLineColor(GT_Cable_Color);
	GT_cable4->SetLineColor(GT_Cable_Color);

	GT_cable1->Draw();
	GT_cable2->Draw();
	GT_cable3->Draw();
	GT_cable4->Draw();

	//-----------------------AURORA--------------
	
	TLine* PMTPSR_cable1 = new TLine(Cx - bridge_W + PMT_PSR_W - 50*cm, bridge_Y - 14*cm,Cx - bridge_W + PMT_PSR_W - 50*cm, bridge_Y + 3*cm);
	TLine* PMTPSR_cable2 = new TLine(Cx - bridge_W + PMT_PSR_W - 40*cm, bridge_Y - 12*cm,Cx - bridge_W + PMT_PSR_W - 40*cm, bridge_Y + 3*cm);
	TLine* PMTPSR_cable3 = new TLine(Cx - bridge_W + PMT_PSR_W - 30*cm, bridge_Y - 10*cm,Cx - bridge_W + PMT_PSR_W - 30*cm, bridge_Y + 3*cm);
	TLine* PMTPSR_cable4 = new TLine(Cx - bridge_W + PMT_PSR_W - 20*cm, bridge_Y - 8*cm,Cx - bridge_W + PMT_PSR_W - 20*cm, bridge_Y + 3*cm);

	PMTPSR_cable1->SetLineWidth(2);
	PMTPSR_cable2->SetLineWidth(2);
	PMTPSR_cable3->SetLineWidth(2);
	PMTPSR_cable4->SetLineWidth(2);
	
	PMTPSR_cable1->SetLineColor(AURORA_Cable_Color);
	PMTPSR_cable2->SetLineColor(AURORA_Cable_Color);
	PMTPSR_cable3->SetLineColor(AURORA_Cable_Color);
	PMTPSR_cable4->SetLineColor(AURORA_Cable_Color);
	
	PMTPSR_cable1->Draw();
	PMTPSR_cable2->Draw();
	PMTPSR_cable3->Draw();
	PMTPSR_cable4->Draw();
	

        double led1_tmp_X = Cx - PMT_R*sin(145./180*pi);
        double led1_tmp_Y = Cy - PMT_R*cos(145./180*pi);

        double led2_tmp_X = Cx - 0.98*PMT_R*sin(148./180*pi);
        double led2_tmp_Y = Cy - 0.98*PMT_R*cos(148./180*pi);

	//TCurlyLine* AURORA_cable1 = new TCurlyLine(Cx - bridge_W + PMT_PSR_W - 50*cm, bridge_Y - 14*cm, led1_tmp_X -5*cm, led1_tmp_Y + led_L/2  ,0.04,0.002);
	//TCurlyLine* AURORA_cable2 = new TCurlyLine(Cx - bridge_W + PMT_PSR_W - 40*cm, bridge_Y - 12*cm, led2_tmp_X, led2_tmp_Y + led_L/2  ,0.04,0.002);
	//TCurlyLine* AURORA_cable3 = new TCurlyLine(Cx - bridge_W + PMT_PSR_W - 30*cm, bridge_Y - 10*cm, led3_X, led3_Y + led_L/2  ,0.04,0.002);
	//TCurlyLine* AURORA_cable4 = new TCurlyLine(Cx - bridge_W + PMT_PSR_W - 20*cm, bridge_Y - 8*cm, led4_X, led4_Y + led_L/2  ,0.04,0.002);

	TLine* AURORA_cable1 = new TLine(Cx - bridge_W + PMT_PSR_W - 50*cm, bridge_Y - 14*cm, led1_tmp_X - 10*cm, led1_tmp_Y + led_L/2);
	TLine* AURORA_cable2 = new TLine(Cx - bridge_W + PMT_PSR_W - 40*cm, bridge_Y - 12*cm, led2_tmp_X, led2_tmp_Y + led_L/2);
	TLine* AURORA_cable3 = new TLine(Cx - bridge_W + PMT_PSR_W - 30*cm, bridge_Y - 10*cm, led3_X, led3_Y + led_L/2);
	TLine* AURORA_cable4 = new TLine(Cx - bridge_W + PMT_PSR_W - 20*cm, bridge_Y - 8.*cm, led4_X, led4_Y + led_L/2);


	AURORA_cable1->SetLineColor(AURORA_Cable_Color);
	AURORA_cable2->SetLineColor(AURORA_Cable_Color);
	AURORA_cable3->SetLineColor(AURORA_Cable_Color);
	AURORA_cable4->SetLineColor(AURORA_Cable_Color);

	AURORA_cable1->SetLineWidth(2);
	AURORA_cable1->Draw();
	AURORA_cable2->SetLineWidth(2);
	AURORA_cable2->Draw();

	AURORA_cable3->SetLineWidth(2);
	AURORA_cable3->Draw();
	AURORA_cable4->SetLineWidth(2);
	AURORA_cable4->Draw();

	TCrown *AURORA_loop_cable1 = new TCrown(Cx,Cy,PMT_R*1.07,PMT_R*1.07,125,180);
	AURORA_loop_cable1->SetLineWidth(2);
	AURORA_loop_cable1->Draw();
	TCrown *AURORA_loop_cable2 = new TCrown(Cx,Cy,PMT_R*1.02,PMT_R*1.02,120,170);
	AURORA_loop_cable2->SetLineWidth(2);
	AURORA_loop_cable2->Draw();

	AURORA_loop_cable1->SetLineColor(AURORA_Cable_Color);
	AURORA_loop_cable2->SetLineColor(AURORA_Cable_Color);

	TLine* led1_cable1 = new TLine(Cx - PMT_R*1.07,Cy,led1_X - led_L/2,led1_Y);
	led1_cable1->SetLineWidth(2);
	led1_cable1->Draw();
	TLine* led1_cable2 = new TLine(Cx - PMT_R*1.02*sin(80./180*pi),Cy + PMT_R*1.02*cos(80./180*pi),led2_X - led_L/2,led2_Y);
	led1_cable2->SetLineWidth(2);
	led1_cable2->Draw();
	led1_cable1->SetLineColor(AURORA_Cable_Color);
	led1_cable2->SetLineColor(AURORA_Cable_Color);

//-----------------------sources-------------------------------

	//--------------ACU sources----------------------------
	TArc *ACU_S1 = new TArc(Cx,Cy,R_source);
	ACU_S1->SetLineColor(kRed);
	ACU_S1->SetFillColor(kRed);
	ACU_S1->Draw();

	TArc *ACU_S2 = new TArc(spool_X2 - spool_L,TurnTable_Y*2/3 + (spool_Y1 + spool_H/2)/3,R_source);
	ACU_S2->SetLineColor(kRed);
	ACU_S2->SetFillColor(kRed);
	ACU_S2->Draw();

	//---------------ROV sources----------------------------
	
	TArc *ROV_S = new TArc(ROV_bot_Cx,ROV_Y-ROV_caple_l,R_source);
	ROV_S->SetLineColor(kRed);
        ROV_S->SetFillColor(kRed);
        ROV_S->Draw();

	//---------------CLS sources--------------------------
	
	TArc *CLS_S1 = new TArc(CLS_S1_X,CLS_S1_Y,R_source);
	CLS_S1->SetLineColor(kRed);
	CLS_S1->SetFillColor(kRed);
	CLS_S1->Draw();

	TArc *CLS_S2 = new TArc(CLS_S2_X,CLS_S2_Y,R_source);
	CLS_S2->SetLineColor(kRed);
	CLS_S2->SetFillColor(kRed);
	CLS_S2->Draw();

	//---------------GT source--------------------------
	
	double GT_S_theta = 240;
	double GT_S_X = Cx + R4*sin(GT_S_theta/180.0*pi);
	double GT_S_Y = Cy + R4*cos(GT_S_theta/180.0*pi);
	TArc *GT_S = new TArc(GT_S_X,GT_S_Y,R_source);
	GT_S->SetLineColor(kRed);
	GT_S->SetFillColor(kRed);
	GT_S->Draw();

//-----------------------spool hold line-------------------

	TLine* shl3 = new TLine(spool_X3 + spool_L/2,house_Y,spool_X3 + spool_L/2,spool_Y3);
	TLine* shl4 = new TLine(spool_X4 + spool_L/2,house_Y,spool_X4 + spool_L/2,spool_Y4);
	TLine* shl5 = new TLine(spool_X5 - spool_L/2,house_Y,spool_X5 - spool_L/2,spool_Y5);
	TLine* shl6 = new TLine(spool_X6 - spool_L/2,house_Y,spool_X6 - spool_L/2,spool_Y6);
	TLine* shl7 = new TLine(spool_X7 + spool_L/2,bridge_Y,spool_X7 + spool_L/2,spool_Y7);
	TLine* shl8 = new TLine(spool_X8 - spool_L/2,bridge_Y,spool_X8 - spool_L/2,spool_Y8);

	shl3->SetLineColor(Hold_Line_Color);
	shl4->SetLineColor(Hold_Line_Color);
	shl5->SetLineColor(Hold_Line_Color);
	shl6->SetLineColor(Hold_Line_Color);
	shl7->SetLineColor(Hold_Line_Color);
	shl8->SetLineColor(Hold_Line_Color);

	shl3->SetLineWidth(3);
	shl4->SetLineWidth(3);
	shl5->SetLineWidth(3);
	shl6->SetLineWidth(3);
	shl7->SetLineWidth(3);
	shl8->SetLineWidth(3);

	shl3->Draw();
	shl4->Draw();
	shl5->Draw();
	shl6->Draw();
	shl7->Draw();
	shl8->Draw();

	TLine* shl_3 = new TLine(spool_X3 + spool_L/3,house_Y,spool_X3 + spool_L/3,spool_Y3);
	TLine* shl_4 = new TLine(spool_X4 + spool_L/3,house_Y,spool_X4 + spool_L/3,spool_Y4);
	TLine* shl_5 = new TLine(spool_X5 - spool_L/3,house_Y,spool_X5 - spool_L/3,spool_Y5);
	TLine* shl_6 = new TLine(spool_X6 - spool_L/3,house_Y,spool_X6 - spool_L/3,spool_Y6);
	TLine* shl_7 = new TLine(spool_X7 + spool_L/3,bridge_Y,spool_X7 +spool_L/3,spool_Y7);
	TLine* shl_8 = new TLine(spool_X8 - spool_L/3,bridge_Y,spool_X8 -spool_L/3,spool_Y8);

	shl_3->SetLineColor(Hold_Line_Color);
	shl_4->SetLineColor(Hold_Line_Color);
	shl_5->SetLineColor(Hold_Line_Color);
	shl_6->SetLineColor(Hold_Line_Color);
	shl_7->SetLineColor(Hold_Line_Color);
	shl_8->SetLineColor(Hold_Line_Color);

	shl_3->SetLineWidth(3);
	shl_4->SetLineWidth(3);
	shl_5->SetLineWidth(3);
	shl_6->SetLineWidth(3);
	shl_7->SetLineWidth(3);
	shl_8->SetLineWidth(3);

	shl_3->Draw();
	shl_4->Draw();
	shl_5->Draw();
	shl_6->Draw();
	shl_7->Draw();
	shl_8->Draw();

	//------------------ source storage hold line-----
	//
	//seems not good if I add hold lines for source storage
	//
	//TLine *shl9 = new TLine(Cx - chimney_W1*5/8,source_storage_Y,Cx - chimney_W1*5/8,house_Y);
	//TLine *shl_9 = new TLine(Cx + chimney_W1*5/8,source_storage_Y,Cx + chimney_W1*5/8,house_Y);
	//shl9->SetLineWidth(3);
	//shl_9->SetLineWidth(3);
	//shl9->SetLineColor(Hold_Line_Color);
	//shl_9->SetLineColor(Hold_Line_Color);

	//shl9->Draw();
	//shl_9->Draw();

//------------------------Tags------------------------------

	//TLatex *ACU = new TLatex(Cx + ACU_W/4,ACU_Y + ACU_H/3,"ACU");
	TLatex *ACU = new TLatex(Cx + ACU_W/4,ACU_Y + ACU_H/3,"Automatic Calibration Unit");
	ACU->SetTextSize(0.035);
	ACU->Draw();

	TLatex *House = new TLatex(Cx - house_W/2*0.95, house_Y + house_H*0.8,"Calibration house");
	House->SetTextSize(0.035);
	House->Draw();

	//---------------------CLS cable tags---------------

	TLatex *Central_Cable_tag = new TLatex(Cx + 20*cm, spool_Y5+20*cm,"Central cable");
	Central_Cable_tag->SetTextSize(0.025);
	Central_Cable_tag->Draw();

	TLatex *Side_Cable_tag = new TLatex(Cx + 25*cm, spool_Y6 + 20*cm,"Side cable");
	Side_Cable_tag->SetTextSize(0.025);
	//Side_Cable_tag->SetTextAngle(35);
	Side_Cable_tag->Draw();

	//-------------------------------------------------
	TLatex *Bridge = new TLatex(Cx + bridge_W, bridge_Y ,"Bridge");
	Bridge->SetTextSize(0.035);
	Bridge->Draw();

	//TArrow TArrow(Double_t x1, Double_t y1, Double_t x2, Double_t y2, Float_t arrowsize = 0.050000000000000003, Option_t* option = ">");
	double tag2ROV = 40*cm;
	TLatex *ROV = new TLatex(ROV_X + ROV_W + tag2ROV -50*cm,ROV_Y + 0.5*ROV_H/2 - 200*cm,"Remotely Operated under-LS Vehicles");
	ROV->SetTextSize(0.03);
	ROV->SetTextAngle(40);
	ROV->Draw();
	//TArrow* ROV_tag_Arr = new TArrow(ROV_X + ROV_W + tag2ROV,ROV_Y + 0.7*ROV_H/2,ROV_X + ROV_W,ROV_Y + 0.7*ROV_H/2,0.015);
	TArrow* ROV_tag_Arr = new TArrow(ROV_X + ROV_W + tag2ROV + 40*cm, ROV_Y + 0.5*ROV_H/2 - 100*cm,ROV_X + ROV_W,ROV_Y + 0.7*ROV_H/2,0.015);
        ROV_tag_Arr->SetLineWidth(3);	
	ROV_tag_Arr->SetLineStyle(9);
        ROV_tag_Arr->Draw();	

	TLatex *ROV_GR_tag = new TLatex(Cx + Guide_rail_L/2,Guide_rail_Y - 6*cm,"ROV guide rail");
	ROV_GR_tag->SetTextSize(0.025);
	ROV_GR_tag->Draw();

	//--------------------GT tags----------------------
	
	TLatex *GT = new TLatex(GT_S_X - 130*cm, GT_S_Y+40*cm,"Guide Tube Calibration System");
	GT->SetTextSize(0.035);
	GT->SetTextAngle(-45);
	GT->Draw();

	TArrow* GT_tag_Arr1 = new TArrow(GT_S_X - 25*cm, GT_S_Y - 45*cm,Cx + R4*sin((GT_S_theta-5)/180.0*pi),Cy + R4*cos((GT_S_theta-5)/180.0*pi),0.015);
	GT_tag_Arr1->SetLineWidth(3);
	GT_tag_Arr1->SetLineStyle(9);
	GT_tag_Arr1->Draw();
	
	//--------------------ACU tags------------------------
	
	TLatex *source = new TLatex(Cx - 35*cm ,Cy - 20*cm,"Source");
	source->SetTextSize(0.035);
	source->Draw();

	//------------------CLS tags-----------------------
	TArrow* CLS_tag_Arr1 = new TArrow(Cx + R1*1.3*sin(70./180*pi),Cy + R1*1.3*cos(70./180*pi),CLS_S2_X*0.5 + (Cx + central_offset)*0.5,CLS_S2_Y*0.5 + (chimney_Y1)*0.5,0.015);
	CLS_tag_Arr1->SetLineWidth(3);
	CLS_tag_Arr1->SetLineStyle(9);
	CLS_tag_Arr1->Draw();
	
	TArrow* CLS_tag_Arr2 = new TArrow(Cx + R1*1.3*sin(70./180*pi),Cy + R1*1.3*cos(70./180*pi),anchor1_point_X*0.3 + CLS_S2_X*0.7,anchor1_point_Y*0.3 + CLS_S2_Y*0.7,0.015);
	CLS_tag_Arr2->SetLineWidth(3);
	CLS_tag_Arr2->SetLineStyle(9);
	CLS_tag_Arr2->Draw();

	TLatex *CLS = new TLatex(Cx + R1*1.3*sin(70./180*pi),Cy + R1*1.3*cos(70./180*pi)+80*cm,"Cable Loop System");
	CLS->SetTextSize(0.035);
	CLS->SetTextAngle(-75);
	CLS->Draw();

	//--------------Source storage tag------------
	
        //TArrow* CLS_tag_Arr2 = new TArrow(Cx + R1*1.3*sin(70./180*pi),Cy + R1*1.3*cos(70./180*pi),anchor1_point_X*0.3 + CLS_S2_X*0.7,anchor1_point_Y*0.3 + CLS_S2_Y*0.7,0.015);
        //CLS_tag_Arr2->SetLineWidth(3);
        //CLS_tag_Arr2->SetLineStyle(9);
        //CLS_tag_Arr2->Draw();

        TLatex *source_storage = new TLatex(Cx + house_W/2 + 30*cm,source_storage_Y-40*cm,"source storage");
        source_storage->SetTextSize(0.03);
	source_storage->SetTextAngle(90);
        source_storage->Draw();
        //TArrow* source_storage_tag_Arr = new TArrow(Cx + source_storage_D*3/8 ,source_storage_Y,Cx + house_W/2 + 30*cm,source_storage_Y-40*cm,0.015);
      TArrow* source_storage_tag_Arr = new TArrow(Cx + house_W/2 + 15*cm,source_storage_Y -20*cm,Cx + source_storage_D*1/2 ,source_storage_Y - storage_cable_L/2,0.015);
        source_storage_tag_Arr->SetLineWidth(3);
        source_storage_tag_Arr->SetLineStyle(9);
        source_storage_tag_Arr->Draw();

	//--------------Anchor tags----------------------------

	//TLatex *Anchor_tag = new TLatex(Cx-R_anchor*sin(anchor2/180*pi)+ anchor_r + 5*cm,Cx+R_anchor*cos(anchor2/180*pi),"Anchor");
	//Anchor_tag->SetTextSize(0.025);
	//Anchor_tag->Draw();
	
	//---------------AURORA tags---------------------------

	TLatex *AURORA_Tag = new TLatex(50*cm,450*cm,"AURORA");
	AURORA_Tag->SetTextSize(0.035);
	AURORA_Tag->Draw();

	TArrow* AURORA_tag_Arr = new TArrow(80*cm,480*cm,100*cm,520*cm,0.015);
        AURORA_tag_Arr->SetLineWidth(3);
        AURORA_tag_Arr->Draw();

//-----------------------Save files-----------------------------
	
	c1->SaveAs("calib_systems.pdf");
	c1->SaveAs("calib_systems.png");
	c1->SaveAs("calib_systems.C");

}
