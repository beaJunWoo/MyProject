#include "Logo.h"
#include "DoubleBuffer.h"
#include "ScenesManager.h"
void Logo::Initalize()
{
#pragma region LogoAnimationShape
	LogoAnimation[0].push_back("����������������������������������");
	LogoAnimation[0].push_back("����������������������������������");
	LogoAnimation[0].push_back("����������������������������������");
	LogoAnimation[0].push_back("����������������������������������");
	LogoAnimation[0].push_back("����������������������������������");
	LogoAnimation[0].push_back("����������������������������������");
	LogoAnimation[0].push_back("����������������������������������");

	LogoAnimation[1].push_back("����������������������������������");
	LogoAnimation[1].push_back("����������������������������������");
	LogoAnimation[1].push_back("����������������������������������");
	LogoAnimation[1].push_back("����������������������������������");
	LogoAnimation[1].push_back("����������������������������������");
	LogoAnimation[1].push_back("����������������������������������");
	LogoAnimation[1].push_back("����������������������������������");

	LogoAnimation[2].push_back("����������������������������������");
	LogoAnimation[2].push_back("����������������������������������");
	LogoAnimation[2].push_back("����������������������������������");
	LogoAnimation[2].push_back("����������������������������������");
	LogoAnimation[2].push_back("����������������������������������");
	LogoAnimation[2].push_back("����������������������������������");
	LogoAnimation[2].push_back("����������������������������������");


	LogoAnimation[3].push_back("����������������������������������");
	LogoAnimation[3].push_back("����������������������������������");
	LogoAnimation[3].push_back("����������������������������������");
	LogoAnimation[3].push_back("����������������������������������");
	LogoAnimation[3].push_back("����������������������������������");
	LogoAnimation[3].push_back("����������������������������������");
	LogoAnimation[3].push_back("����������������������������������");

	LogoAnimation[4].push_back("����������������������������������");
	LogoAnimation[4].push_back("����������������������������������");
	LogoAnimation[4].push_back("����������������������������������");
	LogoAnimation[4].push_back("����������������������������������");
	LogoAnimation[4].push_back("����������������������������������");
	LogoAnimation[4].push_back("����������������������������������");
	LogoAnimation[4].push_back("����������������������������������");


	LogoAnimation[5].push_back("����������������������������������");
	LogoAnimation[5].push_back("����������������������������������");
	LogoAnimation[5].push_back("����������������������������������");
	LogoAnimation[5].push_back("����������������������������������");
	LogoAnimation[5].push_back("����������������������������������");
	LogoAnimation[5].push_back("����������������������������������");
	LogoAnimation[5].push_back("����������������������������������");


	LogoAnimation[6].push_back("����������������������������������");
	LogoAnimation[6].push_back("����������������������������������");
	LogoAnimation[6].push_back("����������������������������������");
	LogoAnimation[6].push_back("����������������������������������");
	LogoAnimation[6].push_back("����������������������������������");
	LogoAnimation[6].push_back("����������������������������������");
	LogoAnimation[6].push_back("����������������������������������");

	LogoAnimation[7].push_back("����������������������������������");
	LogoAnimation[7].push_back("����������������������������������");
	LogoAnimation[7].push_back("����������������������������������");
	LogoAnimation[7].push_back("����������������������������������");
	LogoAnimation[7].push_back("����������������������������������");
	LogoAnimation[7].push_back("����������������������������������");
	LogoAnimation[7].push_back("����������������������������������");

	LogoAnimation[8].push_back("����������������������������������");
	LogoAnimation[8].push_back("����������������������������������");
	LogoAnimation[8].push_back("����������������������������������");
	LogoAnimation[8].push_back("����������������������������������");
	LogoAnimation[8].push_back("����������������������������������");
	LogoAnimation[8].push_back("����������������������������������");
	LogoAnimation[8].push_back("����������������������������������");


	LogoAnimation[9].push_back("����������������������������������");
	LogoAnimation[9].push_back("����������������������������������");
	LogoAnimation[9].push_back("����������������������������������");
	LogoAnimation[9].push_back("����������������������������������");
	LogoAnimation[9].push_back("����������������������������������");
	LogoAnimation[9].push_back("����������������������������������");
	LogoAnimation[9].push_back("����������������������������������");


	LogoAnimation[10].push_back("����������������������������������");
	LogoAnimation[10].push_back("����������������������������������");
	LogoAnimation[10].push_back("����������������������������������");
	LogoAnimation[10].push_back("����������������������������������");
	LogoAnimation[10].push_back("����������������������������������");
	LogoAnimation[10].push_back("����������������������������������");
	LogoAnimation[10].push_back("����������������������������������");

	LogoAnimation[11].push_back("����������������������������������");
	LogoAnimation[11].push_back("����������������������������������");
	LogoAnimation[11].push_back("����������������������������������");
	LogoAnimation[11].push_back("����������������������������������");
	LogoAnimation[11].push_back("����������������������������������");
	LogoAnimation[11].push_back("����������������������������������");
	LogoAnimation[11].push_back("����������������������������������");

	LogoAnimation[12].push_back("����������������������������������");
	LogoAnimation[12].push_back("����������������������������������");
	LogoAnimation[12].push_back("����������������������������������");
	LogoAnimation[12].push_back("����������������������������������");
	LogoAnimation[12].push_back("����������������������������������");
	LogoAnimation[12].push_back("����������������������������������");
	LogoAnimation[12].push_back("����������������������������������");

	LogoAnimation[13].push_back("����������������������������������");
	LogoAnimation[13].push_back("����������������������������������");
	LogoAnimation[13].push_back("����������������������������������");
	LogoAnimation[13].push_back("����������������������������������");
	LogoAnimation[13].push_back("����������������������������������");
	LogoAnimation[13].push_back("����������������������������������");
	LogoAnimation[13].push_back("����������������������������������");

	LogoAnimation[14].push_back("����������������������������������");
	LogoAnimation[14].push_back("����������������������������������");
	LogoAnimation[14].push_back("����������������������������������");
	LogoAnimation[14].push_back("����������������������������������");
	LogoAnimation[14].push_back("����������������������������������");
	LogoAnimation[14].push_back("����������������������������������");
	LogoAnimation[14].push_back("����������������������������������");

	LogoAnimation[15].push_back("����������������������������������");
	LogoAnimation[15].push_back("����������������������������������");
	LogoAnimation[15].push_back("����������������������������������");
	LogoAnimation[15].push_back("����������������������������������");
	LogoAnimation[15].push_back("����������������������������������");
	LogoAnimation[15].push_back("����������������������������������");
	LogoAnimation[15].push_back("����������������������������������");

	LogoAnimation[16].push_back("����������������������������������");
	LogoAnimation[16].push_back("����������������������������������");
	LogoAnimation[16].push_back("����������������������������������");
	LogoAnimation[16].push_back("����������������������������������");
	LogoAnimation[16].push_back("����������������������������������");
	LogoAnimation[16].push_back("����������������������������������");
	LogoAnimation[16].push_back("����������������������������������");

	LogoAnimation[17].push_back("����������������������������������");
	LogoAnimation[17].push_back("����������������������������������");
	LogoAnimation[17].push_back("����������������������������������");
	LogoAnimation[17].push_back("����������������������������������");
	LogoAnimation[17].push_back("����������������������������������");
	LogoAnimation[17].push_back("����������������������������������");
	LogoAnimation[17].push_back("����������������������������������");

	LogoAnimation[18].push_back("����������������������������������");
	LogoAnimation[18].push_back("����������������������������������");
	LogoAnimation[18].push_back("����������������������������������");
	LogoAnimation[18].push_back("����������������������������������");
	LogoAnimation[18].push_back("����������������������������������");
	LogoAnimation[18].push_back("����������������������������������");
	LogoAnimation[18].push_back("����������������������������������");

	LogoAnimation[19].push_back("����������������������������������");
	LogoAnimation[19].push_back("����������������������������������");
	LogoAnimation[19].push_back("����������������������������������");
	LogoAnimation[19].push_back("����������������������������������");
	LogoAnimation[19].push_back("����������������������������������");
	LogoAnimation[19].push_back("����������������������������������");
	LogoAnimation[19].push_back("����������������������������������");

	LogoAnimation[20].push_back("����������������������������������");
	LogoAnimation[20].push_back("����������������������������������");
	LogoAnimation[20].push_back("����������������������������������");
	LogoAnimation[20].push_back("����������������������������������");
	LogoAnimation[20].push_back("����������������������������������");
	LogoAnimation[20].push_back("����������������������������������");
	LogoAnimation[20].push_back("����������������������������������");

	LogoAnimation[21].push_back("����������������������������������");
	LogoAnimation[21].push_back("����������������������������������");
	LogoAnimation[21].push_back("����������������������������������");
	LogoAnimation[21].push_back("����������������������������������");
	LogoAnimation[21].push_back("����������������������������������");
	LogoAnimation[21].push_back("����������������������������������");
	LogoAnimation[21].push_back("����������������������������������");

	LogoAnimation[22].push_back("����������������������������������");
	LogoAnimation[22].push_back("����������������������������������");
	LogoAnimation[22].push_back("����������������������������������");
	LogoAnimation[22].push_back("����������������������������������");
	LogoAnimation[22].push_back("����������������������������������");
	LogoAnimation[22].push_back("����������������������������������");
	LogoAnimation[22].push_back("����������������������������������");
			
	LogoAnimation[23].push_back("����������������������������������");
	LogoAnimation[23].push_back("����������������������������������");
	LogoAnimation[23].push_back("����������������������������������");
	LogoAnimation[23].push_back("����������������������������������");
	LogoAnimation[23].push_back("����������������������������������");
	LogoAnimation[23].push_back("����������������������������������");
	LogoAnimation[23].push_back("����������������������������������");
				 
	LogoAnimation[24].push_back("����������������������������������");
	LogoAnimation[24].push_back("����������������������������������");
	LogoAnimation[24].push_back("����������������������������������");
	LogoAnimation[24].push_back("����������������������������������");
	LogoAnimation[24].push_back("����������������������������������");
	LogoAnimation[24].push_back("����������������������������������");
	LogoAnimation[24].push_back("����������������������������������");
				
	LogoAnimation[25].push_back("����������������������������������");
	LogoAnimation[25].push_back("����������������������������������");
	LogoAnimation[25].push_back("����������������������������������");
	LogoAnimation[25].push_back("����������������������������������");
	LogoAnimation[25].push_back("����������������������������������");
	LogoAnimation[25].push_back("����������������������������������");
	LogoAnimation[25].push_back("����������������������������������");
			
	LogoAnimation[26].push_back("����������������������������������");
	LogoAnimation[26].push_back("����������������������������������");
	LogoAnimation[26].push_back("����������������������������������");
	LogoAnimation[26].push_back("����������������������������������");
	LogoAnimation[26].push_back("����������������������������������");
	LogoAnimation[26].push_back("����������������������������������");
	LogoAnimation[26].push_back("����������������������������������");
				
	LogoAnimation[27].push_back("����������������������������������");
	LogoAnimation[27].push_back("����������������������������������");
	LogoAnimation[27].push_back("����������������������������������");
	LogoAnimation[27].push_back("����������������������������������");
	LogoAnimation[27].push_back("����������������������������������");
	LogoAnimation[27].push_back("����������������������������������");
	LogoAnimation[27].push_back("����������������������������������");
			
	LogoAnimation[28].push_back("����������������������������������");
	LogoAnimation[28].push_back("����������������������������������");
	LogoAnimation[28].push_back("����������������������������������");
	LogoAnimation[28].push_back("����������������������������������");
	LogoAnimation[28].push_back("����������������������������������");
	LogoAnimation[28].push_back("����������������������������������");
	LogoAnimation[28].push_back("����������������������������������");
				 
	LogoAnimation[29].push_back("����������������������������������");
	LogoAnimation[29].push_back("����������������������������������");
	LogoAnimation[29].push_back("����������������������������������");
	LogoAnimation[29].push_back("����������������������������������");
	LogoAnimation[29].push_back("����������������������������������");
	LogoAnimation[29].push_back("����������������������������������");
	LogoAnimation[29].push_back("����������������������������������");
			
	LogoAnimation[30].push_back("����������������������������������");
	LogoAnimation[30].push_back("����������������������������������");
	LogoAnimation[30].push_back("����������������������������������");
	LogoAnimation[30].push_back("����������������������������������");
	LogoAnimation[30].push_back("����������������������������������");
	LogoAnimation[30].push_back("����������������������������������");
	LogoAnimation[30].push_back("����������������������������������");
				
	LogoAnimation[31].push_back("����������������������������������");
	LogoAnimation[31].push_back("����������������������������������");
	LogoAnimation[31].push_back("����������������������������������");
	LogoAnimation[31].push_back("����������������������������������");
	LogoAnimation[31].push_back("����������������������������������");
	LogoAnimation[31].push_back("����������������������������������");
	LogoAnimation[31].push_back("����������������������������������");
			
	LogoAnimation[32].push_back("����������������������������������");
	LogoAnimation[32].push_back("����������������������������������");
	LogoAnimation[32].push_back("����������������������������������");
	LogoAnimation[32].push_back("����������������������������������");
	LogoAnimation[32].push_back("����������������������������������");
	LogoAnimation[32].push_back("����������������������������������");
	LogoAnimation[32].push_back("����������������������������������");
			
	LogoAnimation[33].push_back("����������������������������������");
	LogoAnimation[33].push_back("����������������������������������");
	LogoAnimation[33].push_back("����������������������������������");
	LogoAnimation[33].push_back("����������������������������������");
	LogoAnimation[33].push_back("����������������������������������");
	LogoAnimation[33].push_back("����������������������������������");
	LogoAnimation[33].push_back("����������������������������������");
				
	LogoAnimation[34].push_back("����������������������������������");
	LogoAnimation[34].push_back("����������������������������������");
	LogoAnimation[34].push_back("����������������������������������");
	LogoAnimation[34].push_back("����������������������������������");
	LogoAnimation[34].push_back("����������������������������������");
	LogoAnimation[34].push_back("����������������������������������");
	LogoAnimation[34].push_back("����������������������������������");
				  
	LogoAnimation[35].push_back("����������������������������������");
	LogoAnimation[35].push_back("����������������������������������");
	LogoAnimation[35].push_back("����������������������������������");
	LogoAnimation[35].push_back("����������������������������������");
	LogoAnimation[35].push_back("����������������������������������");
	LogoAnimation[35].push_back("����������������������������������");
	LogoAnimation[35].push_back("����������������������������������");


	LogoAnimation[36].push_back("����������������������������������");
	LogoAnimation[36].push_back("����������������������������������");
	LogoAnimation[36].push_back("����������������������������������");
	LogoAnimation[36].push_back("����������������������������������");
	LogoAnimation[36].push_back("����������������������������������");
	LogoAnimation[36].push_back("����������������������������������");
	LogoAnimation[36].push_back("����������������������������������");

	LogoAnimation[37].push_back("����������������������������������");
	LogoAnimation[37].push_back("����������������������������������");
	LogoAnimation[37].push_back("����������������������������������");
	LogoAnimation[37].push_back("����������������������������������");
	LogoAnimation[37].push_back("����������������������������������");
	LogoAnimation[37].push_back("����������������������������������");
	LogoAnimation[37].push_back("����������������������������������");


	LogoAnimation[38].push_back("����������������������������������");
	LogoAnimation[38].push_back("����������������������������������");
	LogoAnimation[38].push_back("����������������������������������");
	LogoAnimation[38].push_back("����������������������������������");
	LogoAnimation[38].push_back("����������������������������������");
	LogoAnimation[38].push_back("����������������������������������");
	LogoAnimation[38].push_back("����������������������������������");


	LogoAnimation[39].push_back("����������������������������������");
	LogoAnimation[39].push_back("����������������������������������");
	LogoAnimation[39].push_back("����������������������������������");
	LogoAnimation[39].push_back("����������������������������������");
	LogoAnimation[39].push_back("����������������������������������");
	LogoAnimation[39].push_back("����������������������������������");
	LogoAnimation[39].push_back("����������������������������������");

	LogoAnimation[40].push_back("����������������������������������");
	LogoAnimation[40].push_back("����������������������������������");
	LogoAnimation[40].push_back("����������������������������������");
	LogoAnimation[40].push_back("����������������������������������");
	LogoAnimation[40].push_back("����������������������������������");
	LogoAnimation[40].push_back("����������������������������������");
	LogoAnimation[40].push_back("����������������������������������");
				  
	LogoAnimation[41].push_back("����������������������������������");
	LogoAnimation[41].push_back("����������������������������������");
	LogoAnimation[41].push_back("����������������������������������");
	LogoAnimation[41].push_back("����������������������������������");
	LogoAnimation[41].push_back("����������������������������������");
	LogoAnimation[41].push_back("����������������������������������");
	LogoAnimation[41].push_back("����������������������������������");
				  
	LogoAnimation[42].push_back("����������������������������������");
	LogoAnimation[42].push_back("����������������������������������");
	LogoAnimation[42].push_back("����������������������������������");
	LogoAnimation[42].push_back("����������������������������������");
	LogoAnimation[42].push_back("����������������������������������");
	LogoAnimation[42].push_back("����������������������������������");
	LogoAnimation[42].push_back("����������������������������������");
				
	LogoAnimation[43].push_back("����������������������������������");
	LogoAnimation[43].push_back("����������������������������������");
	LogoAnimation[43].push_back("����������������������������������");
	LogoAnimation[43].push_back("����������������������������������");
	LogoAnimation[43].push_back("����������������������������������");
	LogoAnimation[43].push_back("����������������������������������");
	LogoAnimation[43].push_back("����������������������������������");
			
	LogoAnimation[44].push_back("����������������������������������");
	LogoAnimation[44].push_back("����������������������������������");
	LogoAnimation[44].push_back("����������������������������������");
	LogoAnimation[44].push_back("����������������������������������");
	LogoAnimation[44].push_back("����������������������������������");
	LogoAnimation[44].push_back("����������������������������������");
	LogoAnimation[44].push_back("����������������������������������");
				 
	LogoAnimation[45].push_back("����������������������������������");
	LogoAnimation[45].push_back("����������������������������������");
	LogoAnimation[45].push_back("����������������������������������");
	LogoAnimation[45].push_back("����������������������������������");
	LogoAnimation[45].push_back("����������������������������������");
	LogoAnimation[45].push_back("����������������������������������");
	LogoAnimation[45].push_back("����������������������������������");

	LogoAnimation[46].push_back("����������������������������������");
	LogoAnimation[46].push_back("����������������������������������");
	LogoAnimation[46].push_back("����������������������������������");
	LogoAnimation[46].push_back("����������������������������������");
	LogoAnimation[46].push_back("����������������������������������");
	LogoAnimation[46].push_back("����������������������������������");
	LogoAnimation[46].push_back("����������������������������������");

	LogoAnimation[47].push_back("����������������������������������");
	LogoAnimation[47].push_back("����������������������������������");
	LogoAnimation[47].push_back("����������������������������������");
	LogoAnimation[47].push_back("����������������������������������");
	LogoAnimation[47].push_back("����������������������������������");
	LogoAnimation[47].push_back("����������������������������������");
	LogoAnimation[47].push_back("����������������������������������");
	
	LogoAnimation[48].push_back("����������������������������������");
	LogoAnimation[48].push_back("����������������������������������");
	LogoAnimation[48].push_back("����������������������������������");
	LogoAnimation[48].push_back("����������������������������������");
	LogoAnimation[48].push_back("����������������������������������");
	LogoAnimation[48].push_back("����������������������������������");
	LogoAnimation[48].push_back("����������������������������������");

	LogoAnimation[49].push_back("����������������������������������");
	LogoAnimation[49].push_back("����������������������������������");
	LogoAnimation[49].push_back("����������������������������������");
	LogoAnimation[49].push_back("����������������������������������");
	LogoAnimation[49].push_back("����������������������������������");
	LogoAnimation[49].push_back("����������������������������������");
	LogoAnimation[49].push_back("����������������������������������");

	LogoAnimation[50].push_back("����������������������������������");
	LogoAnimation[50].push_back("����������������������������������");
	LogoAnimation[50].push_back("����������������������������������");
	LogoAnimation[50].push_back("����������������������������������");
	LogoAnimation[50].push_back("����������������������������������");
	LogoAnimation[50].push_back("����������������������������������");
	LogoAnimation[50].push_back("����������������������������������");
		
	LogoAnimation[51].push_back("����������������������������������");
	LogoAnimation[51].push_back("����������������������������������");
	LogoAnimation[51].push_back("����������������������������������");
	LogoAnimation[51].push_back("����������������������������������");
	LogoAnimation[51].push_back("����������������������������������");
	LogoAnimation[51].push_back("����������������������������������");
	LogoAnimation[51].push_back("����������������������������������");
		
	LogoAnimation[52].push_back("����������������������������������");
	LogoAnimation[52].push_back("����������������������������������");
	LogoAnimation[52].push_back("����������������������������������");
	LogoAnimation[52].push_back("����������������������������������");
	LogoAnimation[52].push_back("����������������������������������");
	LogoAnimation[52].push_back("����������������������������������");
	LogoAnimation[52].push_back("����������������������������������");
			
	LogoAnimation[53].push_back("����������������������������������");
	LogoAnimation[53].push_back("����������������������������������");
	LogoAnimation[53].push_back("����������������������������������");
	LogoAnimation[53].push_back("����������������������������������");
	LogoAnimation[53].push_back("����������������������������������");
	LogoAnimation[53].push_back("����������������������������������");
	LogoAnimation[53].push_back("����������������������������������");
			
	LogoAnimation[54].push_back("����������������������������������");
	LogoAnimation[54].push_back("����������������������������������");
	LogoAnimation[54].push_back("����������������������������������");
	LogoAnimation[54].push_back("����������������������������������");
	LogoAnimation[54].push_back("����������������������������������");
	LogoAnimation[54].push_back("����������������������������������");
	LogoAnimation[54].push_back("����������������������������������");
			
	LogoAnimation[55].push_back("����������������������������������");
	LogoAnimation[55].push_back("����������������������������������");
	LogoAnimation[55].push_back("����������������������������������");
	LogoAnimation[55].push_back("����������������������������������");
	LogoAnimation[55].push_back("����������������������������������");
	LogoAnimation[55].push_back("����������������������������������");
	LogoAnimation[55].push_back("����������������������������������");
			
	LogoAnimation[56].push_back("����������������������������������");
	LogoAnimation[56].push_back("����������������������������������");
	LogoAnimation[56].push_back("����������������������������������");
	LogoAnimation[56].push_back("����������������������������������");
	LogoAnimation[56].push_back("����������������������������������");
	LogoAnimation[56].push_back("����������������������������������");
	LogoAnimation[56].push_back("����������������������������������");
		
	LogoAnimation[57].push_back("����������������������������������");
	LogoAnimation[57].push_back("����������������������������������");
	LogoAnimation[57].push_back("����������������������������������");
	LogoAnimation[57].push_back("����������������������������������");
	LogoAnimation[57].push_back("����������������������������������");
	LogoAnimation[57].push_back("����������������������������������");
	LogoAnimation[57].push_back("����������������������������������");
		
	LogoAnimation[58].push_back("����������������������������������");
	LogoAnimation[58].push_back("����������������������������������");
	LogoAnimation[58].push_back("����������������������������������");
	LogoAnimation[58].push_back("����������������������������������");
	LogoAnimation[58].push_back("����������������������������������");
	LogoAnimation[58].push_back("����������������������������������");
	LogoAnimation[58].push_back("����������������������������������");
		
	LogoAnimation[59].push_back("���������������������������������");
	LogoAnimation[59].push_back("����������������������������������");
	LogoAnimation[59].push_back("����������������������������������");
	LogoAnimation[59].push_back("����������������������������������");
	LogoAnimation[59].push_back("����������������������������������");
	LogoAnimation[59].push_back("����������������������������������");
	LogoAnimation[59].push_back("����������������������������������");

	LogoAnimation[60].push_back("����������������������������������");
	LogoAnimation[60].push_back("����������������������������������");
	LogoAnimation[60].push_back("����������������������������������");
	LogoAnimation[60].push_back("����������������������������������");
	LogoAnimation[60].push_back("����������������������������������");
	LogoAnimation[60].push_back("����������������������������������");
	LogoAnimation[60].push_back("����������������������������������");

	LogoAnimation[61].push_back("����������������������������������");
	LogoAnimation[61].push_back("����������������������������������");
	LogoAnimation[61].push_back("����������������������������������");
	LogoAnimation[61].push_back("����������������������������������");
	LogoAnimation[61].push_back("����������������������������������");
	LogoAnimation[61].push_back("����������������������������������");
	LogoAnimation[61].push_back("����������������������������������");
				
	LogoAnimation[62].push_back("����������������������������������");
	LogoAnimation[62].push_back("����������������������������������");
	LogoAnimation[62].push_back("����������������������������������");
	LogoAnimation[62].push_back("����������������������������������");
	LogoAnimation[62].push_back("����������������������������������");
	LogoAnimation[62].push_back("����������������������������������");
	LogoAnimation[62].push_back("����������������������������������");
				
	LogoAnimation[63].push_back("����������������������������������");
	LogoAnimation[63].push_back("����������������������������������");
	LogoAnimation[63].push_back("����������������������������������");
	LogoAnimation[63].push_back("����������������������������������");
	LogoAnimation[63].push_back("����������������������������������");
	LogoAnimation[63].push_back("����������������������������������");
	LogoAnimation[63].push_back("����������������������������������");
				
	LogoAnimation[64].push_back("����������������������������������");
	LogoAnimation[64].push_back("����������������������������������");
	LogoAnimation[64].push_back("����������������������������������");
	LogoAnimation[64].push_back("����������������������������������");
	LogoAnimation[64].push_back("����������������������������������");
	LogoAnimation[64].push_back("����������������������������������");
	LogoAnimation[64].push_back("����������������������������������");
				
	LogoAnimation[65].push_back("����������������������������������");
	LogoAnimation[65].push_back("����������������������������������");
	LogoAnimation[65].push_back("����������������������������������");
	LogoAnimation[65].push_back("����������������������������������");
	LogoAnimation[65].push_back("����������������������������������");
	LogoAnimation[65].push_back("����������������������������������");
	LogoAnimation[65].push_back("����������������������������������");
				 
	LogoAnimation[66].push_back("����������������������������������");
	LogoAnimation[66].push_back("����������������������������������");
	LogoAnimation[66].push_back("����������������������������������");
	LogoAnimation[66].push_back("����������������������������������");
	LogoAnimation[66].push_back("����������������������������������");
	LogoAnimation[66].push_back("����������������������������������");
	LogoAnimation[66].push_back("����������������������������������");
				 
	LogoAnimation[67].push_back("����������������������������������");
	LogoAnimation[67].push_back("����������������������������������");
	LogoAnimation[67].push_back("����������������������������������");
	LogoAnimation[67].push_back("����������������������������������");
	LogoAnimation[67].push_back("����������������������������������");
	LogoAnimation[67].push_back("����������������������������������");
	LogoAnimation[67].push_back("����������������������������������");
			
	LogoAnimation[68].push_back("����������������������������������");
	LogoAnimation[68].push_back("����������������������������������");
	LogoAnimation[68].push_back("����������������������������������");
	LogoAnimation[68].push_back("����������������������������������");
	LogoAnimation[68].push_back("����������������������������������");
	LogoAnimation[68].push_back("����������������������������������");
	LogoAnimation[68].push_back("����������������������������������");
				
	LogoAnimation[69].push_back("����������������������������������");
	LogoAnimation[69].push_back("����������������������������������");
	LogoAnimation[69].push_back("����������������������������������");
	LogoAnimation[69].push_back("����������������������������������");
	LogoAnimation[69].push_back("����������������������������������");
	LogoAnimation[69].push_back("����������������������������������");
	LogoAnimation[69].push_back("����������������������������������");
			
	LogoAnimation[70].push_back("����������������������������������");
	LogoAnimation[70].push_back("����������������������������������");
	LogoAnimation[70].push_back("����������������������������������");
	LogoAnimation[70].push_back("����������������������������������");
	LogoAnimation[70].push_back("����������������������������������");
	LogoAnimation[70].push_back("����������������������������������");
	LogoAnimation[70].push_back("����������������������������������");
				 
	LogoAnimation[71].push_back("����������������������������������");
	LogoAnimation[71].push_back("����������������������������������");
	LogoAnimation[71].push_back("����������������������������������");
	LogoAnimation[71].push_back("����������������������������������");
	LogoAnimation[71].push_back("����������������������������������");
	LogoAnimation[71].push_back("����������������������������������");
	LogoAnimation[71].push_back("����������������������������������");
				 
	LogoAnimation[72].push_back("����������������������������������");
	LogoAnimation[72].push_back("����������������������������������");
	LogoAnimation[72].push_back("����������������������������������");
	LogoAnimation[72].push_back("����������������������������������");
	LogoAnimation[72].push_back("����������������������������������");
	LogoAnimation[72].push_back("����������������������������������");
	LogoAnimation[72].push_back("����������������������������������");
#pragma endregion

	NowAnimationSceneIndex = 0;
	BlinkTextDelay = 0;
}

void Logo::Progress()
{
	if (GetAsyncKeyState(0X41))
	{
		ScenesManager::Get()->Initalize(MENU);
	}
}

void Logo::Render()
{
	for (int i = 0; i < LogoAnimation[NowAnimationSceneIndex].size(); i++)
	{
		DoubleBuffer::Get()->WriteBuffer(3, 3 + i, LogoAnimation[NowAnimationSceneIndex][i].c_str(), WHITE);
	}

	if (AddIndexDelay % 10 == 0 && NowAnimationSceneIndex<72) { NowAnimationSceneIndex++; }
	AddIndexDelay++;

	if (NowAnimationSceneIndex == 72)
	{
		BlinkTextDelay++;
		if (BlinkTextDelay % 80 > 40)
		{
			DoubleBuffer::Get()->WriteBuffer(10, 15, "[�����Ϸ��� AŰ�� ��������.]", CYAN);
		}
	}
}

void Logo::Release()
{
}
