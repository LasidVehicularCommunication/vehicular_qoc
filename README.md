<div align="center">
  <img src="./assets/brasao_ufba.png" alt="Brasão da UFBA" width="200" height="300"/>
</div>



## I-CARQOC


O I-CAR** (Intelligent Communication Mechanism for Multi-Agent Vehicular Applications) é uma proposta de serviços inteligentes de comunicação para aplicações veiculares, desenvolvida para otimizar a troca de informações entre veículos e infraestrutura em redes veiculares dinâmicas. Baseado em regras, o I-CAR utiliza a qualidade de contexto para adaptar a comunicação, levando em conta o ambiente e as condições das redes, como a capacidade de conexão dos nós e a movimentação dos veículos.

Por meio dessas regras, o I-CAR possibilita que agentes veiculares tomem decisões autônomas sobre a comunicação durante a execução de aplicações, o que contribui para uma troca de dados mais eficiente e segura. A abordagem permite avaliar o estado atual do ambiente, ajustando o comportamento dos agentes de acordo com mudanças contextuais, como congestionamentos ou perda de sinal, para garantir a continuidade da comunicação.

## Índice

- **[Built With](#built-with)**
- **[Montagem de ambiente e configurações](#montagem-de-ambiente-e-configurações)**
- **[Cenários da Simulação](#cenários-da-simulação)**
- **[Tutorial de Execução da Simulação](#tutorial-de-execução-da-simulação)**
- **[Diagrama de Classes](#diagrama-de-classes)**
- **[Documentação do projeto](#documentação-do-projeto)**
- **[Contato](#documentação-do-projeto)**


## Built With

- **[C++](https://learn.microsoft.com/pt-br/cpp/cpp/?view=msvc-170)**: A linguagem de programação utilizada para o desenvolvimento do projeto.
- **[OMNeT++](https://omnetpp.org/)**: Uma plataforma para simulação de redes.
- **[Veins](https://veins.car2x.org/)**: Um framework para simulações de redes veiculares que funciona com OMNeT++.
- **[SUMO](https://www.eclipse.org/sumo/)**: Um simulador de tráfego que é usado para gerar e simular a movimentação de veículos.

## Montagem de ambiente e configurações

Para configurar o ambiente, siga os passos descritos na documentação do Veins: **[Tutorial](https://veins.car2x.org/tutorial/)**


## Cenários da Simulação

A simulação contém quatro cenários distintos, descritos a seguir:

### Cenário 1
- Um grupo de veículos enfileirados em uma única faixa, seguindo da origem ao destino.
- O tráfego é livre e **não há colisão** entre os veículos.

### Cenário 2
- Um grupo de veículos distribuídos aleatoriamente em várias faixas no mesmo sentido, indo da origem ao destino.
- O tráfego é livre e **não há colisão** entre os veículos.

### Cenário 3
- Dois grupos de veículos enfileirados, com tráfego livre e **sem colisão**.
- Um grupo trafega em uma faixa da via, e o outro grupo em uma faixa no sentido oposto, respeitando os sentidos da via.

### Cenário 4
- Dois grupos de veículos distribuídos aleatoriamente nas faixas, com tráfego livre e **sem colisão**.
- Um grupo segue em um sentido, enquanto o outro segue no sentido oposto, respeitando os sentidos da via.

Esses cenários permitem observar o comportamento dos veículos em diferentes configurações de tráfego e sentidos de direção, fornecendo uma visão detalhada para análise da simulação.



## Tutorial de Execução da Simulação

Este tutorial irá guiá-lo pelos passos necessários para rodar a simulação no OMNeT++ utilizando o arquivo `icarqoc.ini`.

### Passos para Executar a Simulação

1. **Abra o OMNeT++** e navegue até o seguinte caminho dentro do projeto: veins/examples/veins

2. **Localize o arquivo `icarqoc.ini`** neste diretório.

3. **Execute a Simulação** a partir do arquivo `icarqoc.ini`:
- Após encontrar o arquivo, inicie a simulação selecionando o cenário desejado.
- Clique em **OK** para confirmar a escolha do cenário.

4. **Rodando a Simulação**:
- Com o cenário configurado, clique em **Run** para iniciar a execução.

![Simulação](assets/simulacao.gif)

5. **Visualização dos Resultados**:
- Após a simulação ser concluída, você poderá visualizar os resultados gerados.
- Os resultados serão salvos em uma ou mais planilhas na mesma pasta onde está o arquivo `icarqoc.ini`.

Agora você está pronto para rodar e analisar a simulação no OMNeT++! 

## Diagrama de Classes

Abaixo está o link para o PDF que ilustra a modelagem de classes utilizada na simulação:

**<a href="https://ibb.co/Q64fD5D" target="_blank">📄 Diagrama de Classe - Modelagem</a>**

## Documentação do projeto

Este projeto utiliza duas documentações diferentes, cada uma com finalidades distintas:

1. **Documentação do código-fonte**:
   - **Descrição**:Detalha as classes, métodos, atributos e suas interações. É útil para entender a implementação e a lógica interna do sistema.

2. **Documentação da arquitetura de rede**:
   - **Descrição**: Baseada nos arquivos `.NED`, apresenta uma visão clara e visual da arquitetura de rede, incluindo módulos, conexões e hierarquias. É ideal para quem busca compreender o design da simulação e a interação entre os componentes.

Ambas as documentações são complementares e fornecem diferentes perspectivas sobre o projeto:
- Use a **[📖 Documentação do código-fonte](https://lasidvehicularcommunication.github.io/vehicular_qoc/docs/indexDoxy)** para explorar os detalhes técnicos do código.
- Use a **[📖 Documentação da arquitetura de rede](https://lasidvehicularcommunication.github.io/vehicular_qoc/docs/indexNeddoc)** para entender o layout e as configurações da simulação.


## Contato

Para perguntas ou feedback, entre em contato através do seguinte e-mail:

- **Email:** lasidvehicularcommunication@gmail.com
