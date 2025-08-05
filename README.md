# Direct Memory Access (DMA)

## O que é DMA?

O **Acesso Direto à Memória (Direct Memory Access - DMA)** é uma funcionalidade presente em sistemas computacionais que permite que dispositivos de hardware transfiram dados diretamente para a memória principal sem a necessidade da intervenção contínua da Unidade Central de Processamento (CPU). Isso melhora o desempenho geral do sistema ao reduzir a sobrecarga do processador em operações de entrada e saída (I/O).

---

## Benefícios do DMA

- **Desempenho melhorado**: Reduz o tempo de processamento, pois a CPU não precisa gerenciar manualmente as transferências de dados.
- **Menor latência**: Permite uma comunicação mais rápida entre os dispositivos e a memória.
- **Eficiência no uso da CPU**: A CPU pode executar outras tarefas enquanto as transferências de dados ocorrem em paralelo.
- **Menos consumo de energia**: Como a CPU não é sobrecarregada, há menor consumo de energia em comparação com operações tradicionais de I/O.

---

## Como o DMA funciona?

1. **Solicitação de DMA**: Um dispositivo (como uma placa de som ou um disco rígido) solicita ao controlador DMA para iniciar uma transferência de dados.
2. **Arbitragem**: O controlador DMA verifica se há permissões para acessar a memória.
3. **Transferência de Dados**: Os dados são transferidos diretamente entre o dispositivo e a memória sem a intervenção da CPU.
4. **Interrupção da CPU**: Quando a transferência é concluída, o controlador DMA pode gerar uma interrupção para informar a CPU que os dados estão disponíveis.

---

## Modos de Operação do DMA

O DMA pode operar em diferentes modos, dependendo da necessidade do sistema:

- **Burst Mode**: Transfere um bloco completo de dados de uma só vez, bloqueando a CPU até a conclusão.
- **Cycle Stealing Mode**: Transfere pequenos blocos de dados enquanto compartilha ciclos de clock com a CPU.
- **Transparent Mode**: Realiza transferências apenas quando a CPU não está utilizando o barramento de dados, garantindo que a CPU não seja interrompida.

---

## Aplicações do DMA

O DMA é amplamente utilizado em:

- **Placas de som** (para reprodução e gravação de áudio sem atrasos)
- **Controladores de disco rígido e SSDs** (para transferências rápidas de arquivos)
- **Placas de rede** (para comunicação eficiente entre dispositivos)
- **Interfaces gráficas** (para carregamento rápido de texturas e gráficos em jogos e aplicativos)
- **Dispositivos embarcados** (como microcontroladores em sistemas embarcados para otimizar operações de I/O)

---

## Canais ADC suportados no ESP32 (ADC1)

Ao utilizar leitura via DMA/I2S com ESP32, **somente canais do ADC1** são suportados. Veja abaixo a tabela dos canais compatíveis:

| Canal (API)      | GPIO correspondente |
|------------------|--------------------|
| ADC1_CHANNEL_0   | GPIO36 (VP)        |
| ADC1_CHANNEL_1   | GPIO37 (VN)        |
| ADC1_CHANNEL_2   | GPIO38             |
| ADC1_CHANNEL_3   | GPIO39             |
| ADC1_CHANNEL_4   | GPIO32             |
| ADC1_CHANNEL_5   | GPIO33             |
| ADC1_CHANNEL_6   | GPIO34             |
| ADC1_CHANNEL_7   | GPIO35             |

> **Observação:** Canais do ADC2 **não** são suportados via DMA/I2S.

---

## Limitação: apenas um canal por vez

> **Importante:**  
> O periférico I2S do ESP32 com suporte a ADC interno **permite a leitura de apenas UM canal do ADC1 por vez via DMA**.  
> Caso precise ler múltiplos canais, é necessário alternar entre eles no software, configurando o canal desejado antes de cada leitura.  
> Não é possível capturar amostras simultâneas de dois ou mais canais usando DMA/I2S interno.

---

## Conclusão

O Direct Memory Access (DMA) é um componente essencial na arquitetura moderna de computadores, permitindo um processamento mais eficiente ao reduzir a carga da CPU em operações de transferência de dados. Seu uso otimiza aplicações que exigem alta taxa de transferência e baixa latência, tornando os sistemas mais rápidos e responsivos.

---

## Referências

- Tanenbaum, A. S. **"Organização Estruturada de Computadores"**
- Stallings, W. **"Arquitetura e Organização de Computadores"**
- Documentação de fabricantes de hardware