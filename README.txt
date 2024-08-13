
Veins - The open source vehicular network simulation framework.

See the Veins website <http://veins.car2x.org/> for a tutorial, documentation,
and publications.

Veins is composed of many parts. See the version control log for a full list of
contributors and modifications. Each part is protected by its own, individual
copyright(s), but can be redistributed and/or modified under an open source
license. License terms are available at the top of each file. Parts that do not
explicitly include license text shall be assumed to be governed by the "GNU
General Public License" as published by the Free Software Foundation -- either
version 2 of the License, or (at your option) any later version
(SPDX-License-Identifier: GPL-2.0-or-later). Parts that are not source code and
do not include license text shall be assumed to allow the Creative Commons
"Attribution-ShareAlike 4.0 International License" as an additional option
(SPDX-License-Identifier: GPL-2.0-or-later OR CC-BY-SA-4.0). Full license texts
are available with the source distribution.

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
