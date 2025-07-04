#include <iikitmini.h> // Biblioteca base do framework Arduino
#include "util/jtask.h"

// Configurações para a geração da senoide:
#define DAC_PIN 25     // Utiliza o canal DAC1 (GPIO25) do ESP32
#define NUMSAMPLES 100 // Número de amostras por período da senoide
uint8_t sineTable[NUMSAMPLES];

// Gera a tabela de valores para a senoide:
void makePoints()
{
    // Mapeamos a senoide (de -1 a 1) para valores de 0 a 255, que o DAC espera.
    for (int i = 0; i < NUMSAMPLES; i++)
    {
        float angle = (2 * PI * i) / NUMSAMPLES;
        float s = sin(angle);
        int dacValue = (int)((s + 1.0) * 127.5); // mapeia: -1 → 0 e 1 → 255
        sineTable[i] = (uint8_t)dacValue;
    }
}

//uint8_t sampleIndex = 0;
void buildWave()
{
    static uint8_t sampleIndex = 0;
    dacWrite(DAC_PIN, sineTable[sampleIndex]);
    sampleIndex = (sampleIndex + 1) % NUMSAMPLES;
}

void setup()
{
    IIKit.setup();
    makePoints();
    //Para gerar uma senoide de 1kHz com 100 amostras, o período total é 1000 µs.
    //Assim, cada amostra deve ser atualizada a cada 1000/100 = 10 µs.
    jtaskAttachFunc(buildWave, 10UL);
}

void loop()
{
    IIKit.loop();
    jtaskLoop(); // Chama o loop de tarefas da jtask para executar as tarefas agendadas.
}
