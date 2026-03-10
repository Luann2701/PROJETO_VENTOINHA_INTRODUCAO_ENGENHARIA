# 🌡️ Termostato com Arduino e Display LCD

Este projeto utiliza um **Arduino Uno** para monitorar a temperatura ambiente via sensor analógico e controlar automaticamente uma ventoinha (cooler) baseando-se em um limiar pré-definido.

---

## 🚀 Funcionalidades
* **Monitoramento em tempo real:** Leitura de temperatura através de sensor analógico.
* **Controle Automático:** Ativação da ventoinha quando a temperatura ultrapassa **21°C**.
* **Interface Visual:** Exibição da temperatura atual e do status do sistema (Ligado/Desligado) em um display LCD 16x2.
* **Feedback Serial:** Envio dos dados de temperatura para o Monitor Serial para depuração.

---

## 🛠️ Componentes Utilizados
* 1x Arduino Uno
* 1x Display LCD 16x2
* 1x Sensor de Temperatura (TMP36)
* 1x Potenciômetro (Contraste do LCD)
* 1x Ventoinha (Motor DC)
* 1x Resistor de 220 Ohms

---

## 🔌 Circuito e Desafios Técnicos
O sensor de temperatura está conectado ao pino analógico **A4**, enquanto a ventoinha é controlada pelo pino digital **D5**.

⚠️ **Nota sobre Gerenciamento de Corrente:**
Durante a simulação, identificou-se que o motor consome cerca de **69.8 mA**, o que excede o limite de segurança de um pino individual do Arduino (40 mA). Para uma montagem física segura, é indispensável o uso de um **transistor NPN** (como o BC548) atuando como chave, evitando danos ao microcontrolador.

---

## 💻 Lógica de Cálculo
O código realiza a conversão da leitura analógica (0 a 1023) para graus Celsius usando a fórmula:
- `tensao = leitura * (5.0 / 1023.0)`
- `temperatura = (tensao - 0.5) * 100`

---

## 📝 Como usar
1. Clone este repositório.
2. Abra o arquivo `.ino` na Arduino IDE ou importe no Tinkercad.
3. Conecte seu Arduino e faça o upload.
4. Abra o Monitor Serial (9600 baud) ou observe o Display LCD.
