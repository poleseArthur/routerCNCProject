#include <string.h>
#include <stdlib.h>
#include <Arduino.h>
#include "driver.h"
#include "lcd.h"

String comando, f_valor, s_aux, cw_aux, ccw_aux, x_aux, y_aux, z_aux, rapido, lento, medio;
char recebe, termina = '0', s_valor[4], cw_valor[4], ccw_valor[4], x_valor[4], y_valor[4], z_valor[4];
int posicoes[8], s_posicao, cw_posicao, ccw_posicao, f_posicao, x_posicao, y_posicao, z_posicao, final_posicao;

void init_serial()
{
  Serial.begin(9600);
  Serial.println("Start");
}

int positions(int atual_posicao, int *posicoes)
{
  int i, proximo;
  for (i = 7; i > 0; i--)
  {
    if (i == 7)
      proximo = posicoes[i];
    else if (atual_posicao < posicoes[i] && posicoes[i] < proximo)
      proximo = posicoes[i];
  }
  return proximo;
}

void commands()
{
  int proximo;
  if (Serial.available() > 0)
  {
    recebe = Serial.read();
    comando.concat(recebe);
    if (comando.startsWith("$") && comando.endsWith("#"))
    {
      s_posicao = comando.indexOf("S=");
      posicoes[0] = s_posicao;

      cw_posicao = comando.indexOf("M3");
      posicoes[1] = cw_posicao;

      ccw_posicao = comando.indexOf("M4");
      posicoes[2] = ccw_posicao;

      f_posicao = comando.indexOf("F=");
      posicoes[3] = f_posicao;

      x_posicao = comando.indexOf("X=");
      posicoes[4] = x_posicao;

      y_posicao = comando.indexOf("Y=");
      posicoes[5] = y_posicao;

      z_posicao = comando.indexOf("Z=");
      posicoes[6] = z_posicao;

      final_posicao = comando.indexOf("#");
      posicoes[7] = final_posicao;

      Serial.print("COMANDOS SERIAL: ");
      Serial.println(comando);

      if (s_posicao > 0)
      {
        proximo = positions(s_posicao, posicoes);
        Serial.print("VALOR DE S: ");
        s_aux = comando.substring(s_posicao + 2, proximo + 1);
        s_aux.toCharArray(s_valor, s_aux.length());
        spindleRPM = atoi(s_valor);
        spindleSerial(spindleRPM);
        Serial.println(spindleRPM);
       }

      if (f_posicao > 0)
      {
        proximo = positions(f_posicao, posicoes);
        Serial.print("VALOR DE F: ");
        f_valor = comando.substring(f_posicao + 2, proximo);
		if(rapido.equals(f_valor) == true)
        setRpm(MAX);
		else if(medio.equals(f_valor) == true)
        setRpm(MED);
		else if(lento.equals(f_valor) == true)
        setRpm(MIN);
        Serial.println(f_valor);
      }

      if (x_posicao > 0)
      {
        proximo = positions(x_posicao, posicoes);
        Serial.print("VALOR DE X: ");
        x_aux = comando.substring(x_posicao + 2, proximo + 1);
        x_aux.toCharArray(x_valor, x_aux.length());
        posX = atoi(x_valor);
        stepX(posX*10);
        Serial.println(posX);
      }

      if (y_posicao > 0)
      {
        proximo = positions(y_posicao, posicoes);
        Serial.print("VALOR DE Y: ");
        y_aux = comando.substring(y_posicao + 2, proximo + 1);
        y_aux.toCharArray(y_valor, y_aux.length());
        posY = atoi(y_valor);
        stepY(posY*10);
        Serial.println(posY);
      }

      if (z_posicao > 0)
      {
        proximo = positions(z_posicao, posicoes);
        Serial.print("VALOR DE Z: ");
        z_aux = comando.substring(z_posicao + 2, proximo + 1);
        z_aux.toCharArray(z_valor, z_aux.length());
        posZ = atoi(z_valor);
        stepZ(posZ*10);
        Serial.println(posZ);
      }
      if(cw_posicao > 0)
      {
        Serial.println("ROTACAO SENTIDO CW: M3");
        inverteSpindle(spindleRPM);
      }
      if(ccw_posicao > 0)
      {
        Serial.println("ROTACAO SENTIDO CCW: M4");
        inverteSpindle(spindleRPM);
      }
      comando = "\0";
    }
  }

}



