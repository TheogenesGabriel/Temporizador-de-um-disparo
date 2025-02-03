#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "hardware/timer.h"

#define LED_R 12
#define LED_G 13
#define LED_B 11  
#define BUTTON 5  

// Variáveis de controle
bool atv_temporizador = false; // Flag 
uint8_t estado_atual = 0;  // Estado atual dos LEDs

// Função para configurar os dispositivos
void setup_disp() {
    gpio_init(LED_R);
    gpio_init(LED_G);
    gpio_init(LED_B);
    gpio_init(BUTTON);
    gpio_set_dir(LED_R, GPIO_OUT);
    gpio_set_dir(LED_G, GPIO_OUT);
    gpio_set_dir(LED_B, GPIO_OUT);
    gpio_set_dir(BUTTON, GPIO_IN);
    gpio_put(LED_R, 0);
    gpio_put(LED_G, 0);
    gpio_put(LED_B, 0);
    gpio_pull_up(BUTTON);
}


// Função de callback do alarme
int64_t alarm_callback(alarm_id_t id, void *user_data) {

    switch (estado_atual) {
        case 1:
            // Estado 1: Led Azul ligado
            gpio_put(LED_R, 1);
            gpio_put(LED_G, 1);
            gpio_put(LED_B, 0);
            break;
        case 2:
            // Estado 2: Led Vermelho apaga
            gpio_put(LED_R, 0);
            gpio_put(LED_G, 1);
            gpio_put(LED_B, 0);
            break;
        case 3:
            // Estado 3: Todos os LEDs desligados
            gpio_put(LED_R, 0);
            gpio_put(LED_G, 0);
            gpio_put(LED_B, 0);
            atv_temporizador = false; // Finaliza o temporizador
            return 0;
    }

    estado_atual++; 
    return 3000000; // Agenda o próximo alarme em 3 segundos (3.000.000 µs)
}

int main() {
    stdio_init_all(); 

    // Configura os LEDs e o botão
    setup_disp();

    while (true) {
        // Verifica se o botão foi pressionado e o temporizador não está ativo
        if (!gpio_get(BUTTON) && !atv_temporizador) {
            estado_atual = 0; 
            atv_temporizador = true; // Ativa o temporizador
            if(estado_atual == 0){
              // Estado 0: Todos os LEDs ligados
              gpio_put(LED_R, 1);
              gpio_put(LED_G, 1);
              gpio_put(LED_B, 1);
              estado_atual++;
            }
            // Agenda o primeiro alarme para 3 segundos (3.000.000 µs)
            add_alarm_in_ms(3000, alarm_callback, NULL, false);
        }
        //atraso para eficência da CPU
        sleep_ms(100);
    }

    return 0;
}