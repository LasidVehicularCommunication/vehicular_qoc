<div align="center">
  <img src="https://www.ufba.br/sites/portal.ufba.br/files/brasao_ufba.jpg" alt="Imagem da UFBA" width="300" height="400"/>
</div>


## I-CARQOC


O I-CAR** (Intelligent Communication Mechanism for Multi-Agent Vehicular Applications) é uma proposta de serviços inteligentes de comunicação para aplicações veiculares, desenvolvida para otimizar a troca de informações entre veículos e infraestrutura em redes veiculares dinâmicas. Baseado em regras, o I-CAR utiliza a qualidade de contexto para adaptar a comunicação, levando em conta o ambiente e as condições das redes, como a capacidade de conexão dos nós e a movimentação dos veículos.

Por meio dessas regras, o I-CAR possibilita que agentes veiculares tomem decisões autônomas sobre a comunicação durante a execução de aplicações, o que contribui para uma troca de dados mais eficiente e segura. A abordagem permite avaliar o estado atual do ambiente, ajustando o comportamento dos agentes de acordo com mudanças contextuais, como congestionamentos ou perda de sinal, para garantir a continuidade da comunicação.


## Built With

- **[C++](https://learn.microsoft.com/pt-br/cpp/cpp/?view=msvc-170)**: A linguagem de programação utilizada para o desenvolvimento do projeto.
- **[OMNeT++](https://omnetpp.org/)**: Uma plataforma para simulação de redes.
- **[Veins](https://veins.car2x.org/)**: Um framework para simulações de redes veiculares que funciona com OMNeT++.
- **[SUMO](https://www.eclipse.org/sumo/)**: Um simulador de tráfego que é usado para gerar e simular a movimentação de veículos.

### Montagem de ambiente e configurações

Para configurar o ambiente, siga os passos descritos na documentação do Veins: **[Tutorial](https://veins.car2x.org/tutorial/)**

## Contato

Para perguntas ou feedback, entre em contato através dos seguintes e-mails:

- **Email 1:** clovis.grj@gmal.com
- **Email 2:** margaretessa@gmail.com

------------------------------------------------------------------------------------------------------------------------------------------------


## Javadoc - Principais Block Tags

### `@author`
- **Descrição**: Indica o autor do código.
- **Usado em**: Classe, Interface.

### `@version`
- **Descrição**: Especifica a versão do código.
- **Usado em**: Classe, Interface.

### `@since`
- **Descrição**: Indica a versão na qual a classe, método, ou atributo foi introduzido.
- **Usado em**: Classe, Interface, Método, Atributo.

### `@param`
- **Descrição**: Descreve um parâmetro de um método ou construtor.
- **Usado em**: Método, Construtor.
- **Formato**: `@param nome_do_parametro descrição`.

### `@return`
- **Descrição**: Descreve o valor de retorno de um método.
- **Usado em**: Método.
- **Formato**: `@return descrição_do_valor_de_retorno`.

### `@throws` ou `@exception`
- **Descrição**: Descreve uma exceção que o método pode lançar.
- **Usado em**: Método.
- **Formato**: `@throws nome_da_exceção descrição`.

### `@deprecated`
- **Descrição**: Indica que a classe, método, ou atributo foi descontinuado e não deve ser mais utilizado.
- **Usado em**: Classe, Interface, Método, Construtor, Atributo.
- **Formato**: `@deprecated descrição_do_motivo`.

### `@see`
- **Descrição**: Indica uma referência para outro elemento relevante.
- **Usado em**: Classe, Interface, Método, Construtor, Atributo.
- **Formato**: `@see referência`.

### `@link`
- **Descrição**: Cria um link embutido para outra parte da documentação.
- **Usado em**: Texto dentro de outra block tag ou descrição.
- **Formato**: `{@link NomeDaClasse#metodo exemplo}`.

### `@linkplain`
- **Descrição**: Similar ao `@link`, mas o link é formatado como texto normal.
- **Usado em**: Texto dentro de outra block tag ou descrição.
- **Formato**: `{@linkplain NomeDaClasse#metodo exemplo}`.

### `@inheritDoc`
- **Descrição**: Indica que a documentação de um método deve ser herdada de sua superclasse ou interface.
- **Usado em**: Descrição de método ou construtor.
- **Formato**: `{@inheritDoc}`.

### `@serial`
- **Descrição**: Descreve a compatibilidade de serialização de um campo.
- **Usado em**: Campo.
- **Formato**: `@serial descrição`.

### `@serialField`
- **Descrição**: Documenta um campo de uma classe serializada.
- **Usado em**: Campo.
- **Formato**: `@serialField nome tipo descrição`.

### `@serialData`
- **Descrição**: Descreve os dados escritos ou lidos por métodos de serialização personalizada.
- **Usado em**: Método.
- **Formato**: `@serialData descrição`.

### `@docRoot`
- **Descrição**: Cria um caminho absoluto para o diretório raiz da documentação.
- **Usado em**: Comentário de Javadoc.
- **Formato**: `{@docRoot}`.

### `@index`
- **Descrição**: Adiciona uma entrada de índice à documentação.
- **Usado em**: Comentário de Javadoc.
- **Formato**: `@index termo_de_busca título_opcional`.

### `@hidden`
- **Descrição**: Indica que o elemento não deve ser exibido na documentação gerada.
- **Usado em**: Qualquer elemento.