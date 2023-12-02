
#define tempo 10
#include <LiquidCrystal.h>  
LiquidCrystal lcd(8, 9, 4, 5, 6, 7); 


// Criação das Variaveis Globais -------------------------------------
 int frequencia = 0;
 int porta;
 String botao;
 int estado = 1;
 int ponto = 0;
 boolean flag = false;
 int aux = 0; 
 int Acertou = 11;
 int Errou = 0;
 int Buzzer = 2; 

//--------------------------------------------------------------------

void setup()   {  
  lcd.begin(16, 2); 
  pinMode (Acertou, OUTPUT);
  pinMode (Errou, OUTPUT);
  pinMode (Buzzer, OUTPUT);
}  

//--------------------------------------------------------------------

void loop()  { 

  switch (estado) {

    case 1: 
            ponto = 0;
            
            lcd.clear();
            lcd.home();  
            lcd.print(" TESTE DE SINTOMAS"); 
            lcd.setCursor(0,1);  
            lcd.print("   DA MEDISCAN!"); 
            
            delay (2000);
            
          
            lcd.clear();
            lcd.home();  
            lcd.print(" USE AS TECLAS"); 
            lcd.setCursor(0,1);  
            lcd.print("   UP e DOWN"); 

            delay (2000);
    
    		lcd.clear();
            lcd.home();  
            lcd.print("PARA ESCOLHER A"); 
            lcd.setCursor(0,1);  
            lcd.print("RESPOSTA CORRETA"); 

            delay (2000);
    
    		lcd.clear();
            lcd.home();  
            lcd.print("E A TECLA *LEFT*"); 
            lcd.setCursor(0,1);  
            lcd.print("PARA RETORNAR");
    
    		delay (2000);
    
    		lcd.clear();
            lcd.home();  
            lcd.print("TECLE SELECT P/"); 
            lcd.setCursor(0,1);  
            lcd.print("  CONFIRMAR"); 

            delay (3000);
    
    		lcd.clear();
            lcd.home();  
            lcd.print(" VAMOS "); 
            lcd.setCursor(0,1);  
            lcd.print(" INICIAR "); 

            delay (3000);

            estado = 2;

            break;
            
    case 2: 
            lcd.clear();
            lcd.home();  
            lcd.print("PRESSIONE SELECT "); 
            lcd.setCursor(0,1);  
            lcd.print("   PARA  INICIAR"); 

            porta = analogRead (0);
            lcd_Shield();

            if (botao == "Select"){
              estado = 110;
            }

            else if (botao != "vazio"){
              tecla_Error();
            }
    
    		delay (200);

            break;
    case 4: 
            lcd.clear();
            lcd.home();  
            lcd.print("DIAGNOSTICO "); 
            lcd.setCursor(7,0);  
            lcd.print(ponto); 
            lcd.setCursor(9,0);  
            lcd.print(":");

            if (ponto >=7){
              lcd.setCursor(0,1);  
              lcd.print("SAUDAVEL");
            }

            if (ponto <=2){
              lcd.setCursor(0,1);  
              lcd.print("MEDICO URGENTE");
            }
    
            if ((ponto > 3) and (ponto < 6)){
              lcd.setCursor(0,1);  
              lcd.print("FIQUE DE OLHO ");
            }

            delay (3000);
            estado = 1;
            ponto = 0;

            

            break;
            
    case 110: 
            lcd.clear();
            lcd.home();  
            lcd.print("Questao 1:"); 
            lcd.setCursor(0,1);  
            lcd.print("CONSOME MT ALCOOL?"); 
            
    		delay (2000);
    
            for(int cont=0; cont <17; cont++){
    			lcd.scrollDisplayLeft();
    			delay (200); 
  			}
    		
    		delay (2000);
    
    		lcd.clear();
            lcd.home();  
            lcd.print("SIM ()"); 
            lcd.setCursor(0,1);  
            lcd.print("NAO ()");
    		
    		delay (200);
    		estado = 111;
    		aux =0; 
    
    		break;
    
    case 111:
            porta = analogRead (0);
            lcd_Shield();

            if (botao == "Cima"){
              
              lcd.clear();
              lcd.home();  
              lcd.print("SIM (X)"); 
              lcd.setCursor(0,1);  
              lcd.print("NAO ()");
              
              flag = true;
              aux++;

            }

            else if (botao == "Baixo"){
              lcd.clear();
              lcd.home();  
              lcd.print("SIM ()"); 
              lcd.setCursor(0,1);  
              lcd.print("NAO (X)");
              
              flag = false;
              aux++;
              
            }
    
    		else if (botao == "Select"){
              if (aux !=0){
                if(flag == true){
                  lcd.clear();
              	  lcd.home();  
                  lcd.print("SINTOMA"); 
                  lcd.setCursor(0,1);  
                  lcd.print("RUIM");
                  digitalWrite(Acertou, HIGH);
                  for (frequencia = 150; frequencia < 1800; frequencia += 1){ 
                     tone(Buzzer, frequencia, tempo); 
                    delay(1);}{       
                  for (frequencia = 1800; frequencia > 150; frequencia -= 1){   
                     tone(Buzzer, frequencia, tempo); 
                    delay(1);}
                    digitalWrite(Acertou, LOW);}
               
                  
                  ponto++;
                  estado = 120;	
                  delay (3000);
                }
                
                if(flag == false){
                  lcd.clear();
              	  lcd.home();  
                  lcd.print("TUDO"); 
                  lcd.setCursor(0,1);  
                  lcd.print("BEM!");
                  digitalWrite(Errou, HIGH);
                  digitalWrite(Buzzer,HIGH);
                  delay (1000);
                  digitalWrite(Errou, LOW);
                  digitalWrite(Buzzer,LOW);
                  
                  estado = 120;	
                  delay (3000);
  
 
                  
                  
                }
              }
              
              else{
                lcd.clear();
                lcd.home();  
                lcd.print("PULOU A PERGUNTA"); 
                lcd.setCursor(0,1);  
                lcd.print("DADOS INCOMPLETOS");
                
				estado = 120;	
                delay (3000);
              }
            }
    
    		else if (botao == "Esquerda"){
              estado = 110;
            }

            else if (botao != "vazio"){
              tecla_Error();
            }

            break;

  
    
    case 120:
            lcd.clear();
            lcd.home();  
            lcd.print("Questao 2:"); 
            lcd.setCursor(0,1);  
            lcd.print("CONSOME TABACO?"); 
            
    		delay (2000);
    
            for(int cont=0; cont <13; cont++){
    			lcd.scrollDisplayLeft();
    			delay (200); 
  			}
    		
    		delay (2000);
    
    		lcd.clear();
            lcd.home();  
            lcd.print("SIM  ()"); 
            lcd.setCursor(0,1);  
            lcd.print("NAO  ()");
    		
    		delay (200);
    		estado = 121;
    		aux =0; 
    
    		break;
    
    case 121:
            porta = analogRead (0);
            lcd_Shield();

            if (botao == "Cima"){
              
              lcd.clear();
              lcd.home();  
              lcd.print("SIM (X)"); 
              lcd.setCursor(0,1);  
              lcd.print("NAO   ()");
              
              flag = false;
              aux++;

            }

            else if (botao == "Baixo"){
              
              lcd.clear();
              lcd.home();  
              lcd.print("SIM  ()"); 
              lcd.setCursor(0,1);  
              lcd.print("NAO   (X)");
              
              flag = true;
              aux++;
              
            }
   
       else if (botao == "Select"){
              if (aux !=0){
                if(flag == true){
                  lcd.clear();
              	  lcd.home();  
                  lcd.print("TUDO"); 
                  lcd.setCursor(0,1);  
                  lcd.print("BEM!");
                  digitalWrite(Acertou, HIGH);
                  for (frequencia = 150; frequencia < 1800; frequencia += 1){ 
                     tone(Buzzer, frequencia, tempo); 
                    delay(1);}{       
                  for (frequencia = 1800; frequencia > 150; frequencia -= 1){   
                     tone(Buzzer, frequencia, tempo); 
                    delay(1);}
                    digitalWrite(Acertou, LOW);}
               
                  
                  ponto++;
                  estado = 130;	
                  delay (3000);
                }
                
                if(flag == false){
                  lcd.clear();
              	  lcd.home();  
                  lcd.print("SINTOMA"); 
                  lcd.setCursor(0,1);  
                  lcd.print("RUIM");
                  digitalWrite(Errou, HIGH);
                  digitalWrite(Buzzer,HIGH);
                  delay (1000);
                  digitalWrite(Errou, LOW);
                  digitalWrite(Buzzer,LOW);
                  
                  estado = 130;	
                  delay (3000);
                }
              }
              
              else{
                lcd.clear();
                lcd.home();  
                lcd.print("PULOU A PERGUNTA"); 
                lcd.setCursor(0,1);  
                lcd.print("DADOS INCOMPLETOS");
                
				estado = 130;	
                delay (3000);
              }
            }
    
    		else if (botao == "Esquerda"){
              estado = 120;
            }

            else if (botao != "vazio"){
              tecla_Error();
            }

            break;
    
    case 130:
            lcd.clear();
            lcd.home();  
            lcd.print("Questao 3:"); 
            lcd.setCursor(0,1);  
            lcd.print("MT INDIGESTAO ?"); 
            
    		delay (2000);
    
            for(int cont=0; cont <9; cont++){
    			lcd.scrollDisplayLeft();
    			delay (200); 
  			}
    		
    		delay (2000);
    
    		lcd.clear();
            lcd.home();  
            lcd.print("SIM()"); 
            lcd.setCursor(0,1);  
            lcd.print("NAO ()");
    		
    		delay (200);
    		estado = 131;
    		aux =0; 
    
    		break;
    
    case 131:
            porta = analogRead (0);
            lcd_Shield();

            if (botao == "Cima"){
              
              lcd.clear();
              lcd.home();  
              lcd.print("SIM(X)"); 
              lcd.setCursor(0,1);  
              lcd.print("NAO ()");
              
              flag = false;
              aux++;

            }

            else if (botao == "Baixo"){
              
              lcd.clear();
              lcd.home();  
              lcd.print("SIM()"); 
              lcd.setCursor(0,1);  
              lcd.print("NAO(X)");
              
              flag = true;
              aux++;
              
            }
    
    	else if (botao == "Select"){
              if (aux !=0){
                if(flag == true){
                  lcd.clear();
              	  lcd.home();  
                  lcd.print("TUDO"); 
                  lcd.setCursor(0,1);  
                  lcd.print("BEM!");
                  digitalWrite(Acertou, HIGH);
                  for (frequencia = 150; frequencia < 1800; frequencia += 1){ 
                     tone(Buzzer, frequencia, tempo); 
                    delay(1);}{       
                  for (frequencia = 1800; frequencia > 150; frequencia -= 1){   
                     tone(Buzzer, frequencia, tempo); 
                    delay(1);}
                    digitalWrite(Acertou, LOW);}
               
                  
                  ponto++;
                  estado = 140;	
                  delay (3000);
                }
                
                if(flag == false){
                  lcd.clear();
              	  lcd.home();  
                  lcd.print("SINTOMA"); 
                  lcd.setCursor(0,1);  
                  lcd.print("RUIM");
                  digitalWrite(Errou, HIGH);
                  digitalWrite(Buzzer,HIGH);
                  delay (1000);
                  digitalWrite(Errou, LOW);
                  digitalWrite(Buzzer,LOW);
                  
                  estado = 140;	
                  delay (3000);
                }
              }
              
              else{
                lcd.clear();
                lcd.home();  
                lcd.print("PULOU A PERGUNTA"); 
                lcd.setCursor(0,1);  
                 lcd.print("DADOS INCOMPLETOS");
                
				estado = 140;	
                delay (3000);
              }
            }
    
    		else if (botao == "Esquerda"){
              estado = 130;
            }

            else if (botao != "vazio"){
              tecla_Error();
            }

            break;
    
    case 140: 
            lcd.clear();
            lcd.home();  
            lcd.print("Questao 4:"); 
            lcd.setCursor(0,1);  
            lcd.print("SANGRAMENTOS INCOMUNS?"); 
            
    		delay (2000);
    
            for(int cont=0; cont <12; cont++){
    			lcd.scrollDisplayLeft();
    			delay (200); 
  			}
    		
    		delay (2000);
    
    		lcd.clear();
            lcd.home();  
            lcd.print("SIM ()"); 
            lcd.setCursor(0,1);  
            lcd.print("NAO ()");
    		
    		delay (200);
    		estado = 141;
    		aux =0; 
    
    		break;
    
    case 141:
            porta = analogRead (0);
            lcd_Shield();

            if (botao == "Cima"){
              
              lcd.clear();
              lcd.home();  
              lcd.print("SIM (X)"); 
              lcd.setCursor(0,1);  
              lcd.print("NAO ()");
              
              flag = false;
              aux++;

            }

            else if (botao == "Baixo"){
              lcd.clear();
              lcd.home();  
              lcd.print("SIM ()"); 
              lcd.setCursor(0,1);  
              lcd.print("NAO (X)");
              
              flag = true;
              aux++;
              
            }
    
    	else if (botao == "Select"){
              if (aux !=0){
                if(flag == true){
                  lcd.clear();
              	  lcd.home();  
                  lcd.print("SINTOMA"); 
                  lcd.setCursor(0,1);  
                  lcd.print("RUIM");
                  digitalWrite(Acertou, HIGH);
                  for (frequencia = 150; frequencia < 1800; frequencia += 1){ 
                     tone(Buzzer, frequencia, tempo); 
                    delay(1);}{       
                  for (frequencia = 1800; frequencia > 150; frequencia -= 1){   
                     tone(Buzzer, frequencia, tempo); 
                    delay(1);}
                    digitalWrite(Acertou, LOW);}
               
                  
                  ponto++;
                  estado = 150;	
                  delay (3000);
                }
                
                if(flag == false){
                  lcd.clear();
              	  lcd.home();  
                  lcd.print("TUDO"); 
                  lcd.setCursor(0,1);  
                  lcd.print("BEM!");
                  digitalWrite(Errou, HIGH);
                  digitalWrite(Buzzer,HIGH);
                  delay (1000);
                  digitalWrite(Errou, LOW);
                  digitalWrite(Buzzer,LOW);
                  estado = 150;	
                  delay (3000);
                }
              }
              
              else{
                lcd.clear();
                lcd.home();  
                lcd.print("PULOU A PERGUNTA"); 
                lcd.setCursor(0,1);  
                lcd.print("DADOS INCOMPLETOS");
                
				estado = 150;	
                delay (3000);
              }
            }
    
    		else if (botao == "Esquerda"){
              estado = 140;
            }

            else if (botao != "vazio"){
              tecla_Error();
            }

            break;
                
    case 150: 
            lcd.clear();
            lcd.home();  
            lcd.print("Questao 5:"); 
            lcd.setCursor(0,1);  
            lcd.print("QUANDO FOI SEU ULTIMO EXAME?"); 
            
    		delay (2000);
    
            for(int cont=0; cont <15; cont++){
    			lcd.scrollDisplayLeft();
    			delay (200); 
  			}
    		
    		delay (2000);
    
    		lcd.clear();
            lcd.home();  
            lcd.print("ESSE ANO ()"); 
            lcd.setCursor(0,1);  
            lcd.print("ANO PASSADO()");
    		
    		delay (200);
    		estado = 151;
    		aux =0; 
    
    		break;
    
    case 151:
            porta = analogRead (0);
            lcd_Shield();

            if (botao == "Cima"){
              
              lcd.clear();
              lcd.home();  
              lcd.print("ESSE ANO (X)"); 
              lcd.setCursor(0,1);  
              lcd.print("ANO PASSADO()");
              
              flag = true;
              aux++;

            }

            else if (botao == "Baixo"){
              lcd.clear();
              lcd.home();  
              lcd.print("ESSE ANO ()"); 
              lcd.setCursor(0,1);  
              lcd.print("ANO PASSADO(X)");
              
              flag = false;
              aux++;
              
            }
    
    		else if (botao == "Select"){
              if (aux !=0){
                if(flag == true){
                  lcd.clear();
              	  lcd.home();  
                  lcd.print("TUDO"); 
                  lcd.setCursor(0,1);  
                  lcd.print("BEM!");
                  digitalWrite(Acertou, HIGH);
                  for (frequencia = 150; frequencia < 1800; frequencia += 1){ 
                     tone(Buzzer, frequencia, tempo); 
                    delay(1);}{       
                  for (frequencia = 1800; frequencia > 150; frequencia -= 1){   
                     tone(Buzzer, frequencia, tempo); 
                    delay(1);}
                    digitalWrite(Acertou, LOW);}
               
                  
                  ponto++;
                  estado = 160;	
                  delay (3000);
                }
                
                if(flag == false){
                  lcd.clear();
              	  lcd.home();  
                  lcd.print("SINTOMA"); 
                  lcd.setCursor(0,1);  
                  lcd.print("RUIM");
                  digitalWrite(Errou, HIGH);
                  digitalWrite(Buzzer,HIGH);
                  delay (1000);
                  digitalWrite(Errou, LOW);
                  digitalWrite(Buzzer,LOW);
                  
                  estado = 160;	
                  delay (3000);
                }
              }
              
              else{
                lcd.clear();
                lcd.home();  
                lcd.print("PULOU A PERGUNTA"); 
                lcd.setCursor(0,1);  
                lcd.print("DADOS INCOMPLETOS");
                
				estado = 160;	
                delay (3000);
              }
            }
    
    		else if (botao == "Esquerda"){
              estado = 150;
            }

            else if (botao != "vazio"){
              tecla_Error();
            }

            break;
    
            
    case 160: 
            lcd.clear();
            lcd.home();  
            lcd.print("Questao 6:"); 
            lcd.setCursor(0,1);  
            lcd.print("EXPOSICAO AO SOL MODERADA?"); 
                     
          
    		delay (2000);
    
            for(int cont=0; cont <12; cont++){
    			lcd.scrollDisplayLeft();
    			delay (200); 
  			}
    		
    		delay (2000);
    
    		lcd.clear();
            lcd.home();  
            lcd.print("NAO ()"); 
            lcd.setCursor(0,1);  
            lcd.print("SIM ()");
    		
    		delay (200);
    		estado = 161;
    		aux =0; 
    
    		break;
    
    case 161:
            porta = analogRead (0);
            lcd_Shield();

            if (botao == "Cima"){
              
              lcd.clear();
              lcd.home();  
              lcd.print("NAO (X)"); 
              lcd.setCursor(0,1);  
              lcd.print("SIM ()");
              
              flag = false;
              aux++;

            }

            else if (botao == "Baixo"){
              lcd.clear();
              lcd.home();  
              lcd.print("NAO ()"); 
              lcd.setCursor(0,1);  
              lcd.print("SIM (X)");
              
              flag = true;
              aux++;
              
            }
    
    		else if (botao == "Select"){
              if (aux !=0){
                if(flag == true){
                  lcd.clear();
              	  lcd.home();  
                  lcd.print("TUDO"); 
                  lcd.setCursor(0,1);  
                  lcd.print("BEM!");
                 digitalWrite(Acertou, HIGH);
                  for (frequencia = 150; frequencia < 1800; frequencia += 1){ 
                     tone(Buzzer, frequencia, tempo); 
                    delay(1);}{       
                  for (frequencia = 1800; frequencia > 150; frequencia -= 1){   
                     tone(Buzzer, frequencia, tempo); 
                    delay(1);}
                    digitalWrite(Acertou, LOW);}
                  
                  ponto++;
                  estado = 170;	
                  delay (3000);
                }
                
                if(flag == false){
                  lcd.clear();
              	  lcd.home();  
                  lcd.print("SINTOMA"); 
                  lcd.setCursor(0,1);  
                  lcd.print("RUIM");
                  digitalWrite(Errou, HIGH);
                  digitalWrite(Buzzer,HIGH);
                  delay (1000);
                  digitalWrite(Errou, LOW);
                  digitalWrite(Buzzer,LOW);
                  
                  estado = 170;	
                  delay (3000);
                }
              }
              
              else{
                lcd.clear();
                lcd.home();  
                lcd.print("PULOU A PERGUNTA"); 
                lcd.setCursor(0,1);  
                lcd.print("DADOS INCOMPLETOS");
                
				estado = 170;	
                delay (3000);
              }
            }
    
    		else if (botao == "Esquerda"){
              estado = 160;
            }

            else if (botao != "vazio"){
              tecla_Error();
            }

            break;
    
    case 170: 
            lcd.clear();
            lcd.home();  
            lcd.print("Questao 7:"); 
            lcd.setCursor(0,1);  
            lcd.print("EXERCICIO FREQUENTE?"); 
            
    		delay (2000);
    
            for(int cont=0; cont <2; cont++){
    			lcd.scrollDisplayLeft();
    			delay (200); 
  			}
    		
    		delay (2000);
    
    		lcd.clear();
            lcd.home();  
            lcd.print("SIM()"); 
            lcd.setCursor(0,1);  
            lcd.print("NAO()");
    		
    		delay (200);
    		estado = 171;
    		aux =0; 
    
    		break;
    
    case 171:
            porta = analogRead (0);
            lcd_Shield();

            if (botao == "Cima"){
              
              lcd.clear();
              lcd.home();  
              lcd.print("SIM(X)"); 
              lcd.setCursor(0,1);  
              lcd.print("NAO()");
              
              flag = false;
              aux++;

            }

            else if (botao == "Baixo"){
              lcd.clear();
              lcd.home();  
              lcd.print("SIM()"); 
              lcd.setCursor(0,1);  
              lcd.print("NAO(X)");
              
              flag = true;
              aux++;
              
            }
    
    		else if (botao == "Select"){
              if (aux !=0){
                if(flag == true){
                  lcd.clear();
              	  lcd.home();  
                  lcd.print("SINTOMA"); 
                  lcd.setCursor(0,1);  
                  lcd.print("RUIM");
                  digitalWrite(Acertou, HIGH);
                  for (frequencia = 150; frequencia < 1800; frequencia += 1){ 
                     tone(Buzzer, frequencia, tempo); 
                    delay(1);}{       
                  for (frequencia = 1800; frequencia > 150; frequencia -= 1){   
                     tone(Buzzer, frequencia, tempo); 
                    delay(1);}
                    digitalWrite(Acertou, LOW);}
                  
                  ponto++;
                  estado = 180;	
                  delay (3000);
                }
                
                if(flag == false){
                  lcd.clear();
              	  lcd.home();  
                  lcd.print("TUDO"); 
                  lcd.setCursor(0,1);  
                  lcd.print("BEM!");
                  digitalWrite(Errou, HIGH);
                  digitalWrite(Buzzer,HIGH);
                  delay (1000);
                  digitalWrite(Errou, LOW);
                  digitalWrite(Buzzer,LOW);
                  
                  estado = 180;	
                  delay (3000);
                }
              }
              
              else{
                lcd.clear();
                lcd.home();  
                lcd.print("PULOU A PERGUNTA"); 
                lcd.setCursor(0,1);  
                lcd.print("DADOS INCOMPLETOS");
                
				estado = 180;	
                delay (3000);
              }
            }
    
    		else if (botao == "Esquerda"){
              estado = 170;
            }

            else if (botao != "vazio"){
              tecla_Error();
            }

            break;
    
    case 180: 
            lcd.clear();
            lcd.home();  
            lcd.print("Questao 8:"); 
            lcd.setCursor(0,1);  
            lcd.print("FAIXA ETARIA?"); 
            
    		delay (2000);
    
            for(int cont=0; cont <11; cont++){
    			lcd.scrollDisplayLeft();
    			delay (200); 
  			}
    		
    		delay (2000);
    
    		lcd.clear();
            lcd.home();  
            lcd.print("JOVEM ()"); 
            lcd.setCursor(0,1);  
            lcd.print("IDOSO ()");
    		
    		delay (200);
    		estado = 181;
    		aux =0; 
    
    		break;
    
    case 181:
            porta = analogRead (0);
            lcd_Shield();

            if (botao == "Cima"){
              
              lcd.clear();
              lcd.home();  
              lcd.print("JOVEM (X)"); 
              lcd.setCursor(0,1);  
              lcd.print("IDOSO ()");
              
              flag = true;
              aux++;

            }

            else if (botao == "Baixo"){
              lcd.clear();
              lcd.home();  
              lcd.print("JOVEM()"); 
              lcd.setCursor(0,1);  
              lcd.print("IDOSO (X)");
              
              flag = false;
              aux++;
              
            }
    
    		else if (botao == "Select"){
              if (aux !=0){
                if(flag == true){
                  lcd.clear();
              	  lcd.home();  
                  lcd.print("TUDO"); 
                  lcd.setCursor(0,1);  
                  lcd.print("BEM!");
                  digitalWrite(Acertou, HIGH);
                  for (frequencia = 150; frequencia < 1800; frequencia += 1){ 
                     tone(Buzzer, frequencia, tempo); 
                    delay(1);}{       
                  for (frequencia = 1800; frequencia > 150; frequencia -= 1){   
                     tone(Buzzer, frequencia, tempo); 
                    delay(1);}
                    digitalWrite(Acertou, LOW);}
                  
                  ponto++;
                  estado = 190;	
                  delay (3000);
                }
                
                if(flag == false){
                  lcd.clear();
              	  lcd.home();  
                  lcd.print("TOME"); 
                  lcd.setCursor(0,1);  
                  lcd.print("CUIDADO");
                  digitalWrite(Errou, HIGH);
                  digitalWrite(Buzzer,HIGH);
                  delay (1000);
                  digitalWrite(Errou, LOW);
                  digitalWrite(Buzzer,LOW);
                  
                  estado = 190;	
                  delay (3000);
                }
              }
              
              else{
                lcd.clear();
                lcd.home();  
                lcd.print("PULOU A PERGUNTA"); 
                lcd.setCursor(0,1);  
                lcd.print("DADOS INCOMPLETOS");
                
				estado = 190;	
                delay (3000);
              }
            }
    
    		else if (botao == "Esquerda"){
              estado = 180;
            }

            else if (botao != "vazio"){
              tecla_Error();
            }

            break;
    
    case 190: 
            lcd.clear();
            lcd.home();  
            lcd.print("Questao 9:"); 
            lcd.setCursor(0,1);  
            lcd.print("VC PESA MUITO?"); 
            
    		delay (2000);
    
            for(int cont=0; cont <8; cont++){
    			lcd.scrollDisplayLeft();
    			delay (200); 
  			}
    		
    		delay (2000);
    
    		lcd.clear();
            lcd.home();  
            lcd.print("NAO ()"); 
            lcd.setCursor(0,1);  
            lcd.print("SIM ()");
    		
    		delay (200);
    		estado = 191;
    		aux =0; 
    
    		break;
    
    case 191:
            porta = analogRead (0);
            lcd_Shield();

            if (botao == "Cima"){
              
              lcd.clear();
              lcd.home();  
              lcd.print("NAO (X)"); 
              lcd.setCursor(0,1);  
              lcd.print("SIM ()");
              
              flag = true;
              aux++;

            }

            else if (botao == "Baixo"){
              lcd.clear();
              lcd.home();  
              lcd.print("NAO ()"); 
              lcd.setCursor(0,1);  
              lcd.print("SIM (X)");
              
              flag = false;
              aux++;
              
            }
    
    		else if (botao == "Select"){
              if (aux !=0){
                if(flag == true){
                  lcd.clear();
              	  lcd.home();  
                  lcd.print("TUDO"); 
                  lcd.setCursor(0,1);  
                  lcd.print("BEM!");
                 digitalWrite(Acertou, HIGH);
                  for (frequencia = 150; frequencia < 1800; frequencia += 1){ 
                     tone(Buzzer, frequencia, tempo); 
                    delay(1);}{       
                  for (frequencia = 1800; frequencia > 150; frequencia -= 1){   
                     tone(Buzzer, frequencia, tempo); 
                    delay(1);}
                    digitalWrite(Acertou, LOW);}
               
                  
                  ponto++;
                  estado = 200;	
                  delay (3000);
                }
                
                if(flag == false){
                  lcd.clear();
              	  lcd.home();  
                  lcd.print("SINTOMA"); 
                  lcd.setCursor(0,1);  
                  lcd.print("RUIM");
                  digitalWrite(Errou, HIGH);
                  digitalWrite(Buzzer,HIGH);
                  delay (1000);
                  digitalWrite(Errou, LOW);
                  digitalWrite(Buzzer,LOW);
                  
                  estado = 200;	
                  delay (3000);
                }
              }
              
              else{
                lcd.clear();
                lcd.home();  
                lcd.print("PULOU A PERGUNTA"); 
                lcd.setCursor(0,1);  
                lcd.print("DADOS INCOMPLETOS");
                
				estado = 200;	
                delay (3000);
              }
            }
    
    		else if (botao == "Esquerda"){
              estado = 190;
            }

            else if (botao != "vazio"){
              tecla_Error();
            }

            break;
    
    case 200: 
            lcd.clear();
            lcd.home();  
            lcd.print("Questao 10:"); 
            lcd.setCursor(0,1);  
            lcd.print("TOMA REMEDIO CONTROLADO?"); 
            
    		delay (2000);
    
            for(int cont=0; cont <9; cont++){
    			lcd.scrollDisplayLeft();
    			delay (200); 
  			}
    		
    		delay (2000);
    
    		lcd.clear();
            lcd.home();  
            lcd.print("SIM ()"); 
            lcd.setCursor(0,1);  
            lcd.print("NAO ()");
    		
    		delay (200);
    		estado = 210;
    		aux =0; 
    
    		break;
    
    case 210:
            porta = analogRead (0);
            lcd_Shield();

            if (botao == "Cima"){
              
              lcd.clear();
              lcd.home();  
              lcd.print("SIM (X)"); 
              lcd.setCursor(0,1);  
              lcd.print("NAO ()");
              
              flag = false;
              aux++;

            }

            else if (botao == "Baixo"){
              lcd.clear();
              lcd.home();  
              lcd.print("SIM ()"); 
              lcd.setCursor(0,1);  
              lcd.print("NAO (X)");
              
              flag = true;
              aux++;
              
            }
    
    		else if (botao == "Select"){
              if (aux !=0){
                if(flag == true){
                  lcd.clear();
              	  lcd.home();  
                  lcd.print("TOME"); 
                  lcd.setCursor(0,1);  
                  lcd.print("CUIDADO!");
                 digitalWrite(Acertou, HIGH);
                  for (frequencia = 150; frequencia < 1800; frequencia += 1){ 
                     tone(Buzzer, frequencia, tempo); 
                    delay(1);}{       
                  for (frequencia = 1800; frequencia > 150; frequencia -= 1){   
                     tone(Buzzer, frequencia, tempo); 
                    delay(1);}
                    digitalWrite(Acertou, LOW);}
               
                  
                  ponto++;
                  estado = 4;	
                  delay (3000);
                }
                
                if(flag == false){
                  lcd.clear();
              	  lcd.home();  
                  lcd.print("TUDO BEM!"); 
                  lcd.setCursor(0,1);  
                  lcd.print("DADOS INCOMPLETOS");
                  digitalWrite(Errou, HIGH);
                  digitalWrite(Buzzer,HIGH);
                  delay (1000);
                  digitalWrite(Errou, LOW);
                  digitalWrite(Buzzer,LOW);
                  estado = 4;	
                  delay (3000);
                }
              }
              
              else{
                lcd.clear();
                lcd.home();  
                lcd.print("PULOU A PERGUNTA"); 
                lcd.setCursor(0,1);  
                lcd.print("DADOS INCOMPLETOS");
                
				estado = 4;	
                delay (3000);
              }
            }
    
    		else if (botao == "Esquerda"){
              estado = 200;
            }

            else if (botao != "vazio"){
              tecla_Error();
            }

            break;
    
  }

}

void lcd_Shield () {

   botao = "vazio";

   if (porta < 100) {  
      botao = "Direita";  
   }  
   else if (porta < 200) {  
      botao = "Cima";  
   }  
   else if (porta < 400){  
      botao = "Baixo";  
   }  
   else if (porta < 600){  
      botao = "Esquerda";  
   }  
   else if (porta < 800){  
      botao = "Select";  
   } 
}

void tecla_Error(){
  lcd.clear();
  lcd.home();
  lcd.print (" Tecla Errada!! ");
  delay (1000); 
}
