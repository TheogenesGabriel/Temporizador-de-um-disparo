# Temporizador Periódico com Raspberry Pi Pico

Este projeto implementa um temporizador periódico utilizando a Raspberry Pi Pico. O sistema aciona um conjunto de LEDs em um ciclo predefinido ao pressionar um botão.

## Funcionalidades
- Pressionar o botão inicia uma sequência de iluminação dos LEDs.
- Os LEDs mudam de estado a cada 3 segundos.
- O ciclo finaliza após três estados e aguarda uma nova ativação pelo botão.

## Hardware Necessário
- Raspberry Pi Pico
- LED Vermelho (conectado ao GPIO 12)
- LED Verde (conectado ao GPIO 13)
- LED Azul (conectado ao GPIO 11)
- Botão (conectado ao GPIO 5)
- Resistores para LEDs e botão (se necessário)

## Configuração dos Pinos
| Componente  | GPIO |
|------------|------|
| LED Vermelho | 12 |
| LED Verde    | 13 |
| LED Azul     | 11 |
| Botão       | 5  |

## Como Funciona
1. O sistema inicia com todos os LEDs apagados.
2. Quando o botão é pressionado, o temporizador é ativado e os LEDs seguem a seguinte sequência:
   - Estado 0: Todos os LEDs acendem.
   - Estado 1: Apenas o LED azul permanece aceso.
   - Estado 2: O LED vermelho apaga, permanecendo apenas o verde.
   - Estado 3: Todos os LEDs se apagam e o ciclo é concluído.

## Compilando e Executando
1. Configure o ambiente de desenvolvimento da Raspberry Pi Pico.
2. Compile o código utilizando o SDK do RP2040.
3. Carregue o binário para a Pico e execute o programa.
4. Abra o wokwi intregrado no VScode e visualize a simulação.

## Autor
Theógenes Gabriel Araújo de Andrade



