Como contribuir

Aceitamos contribuições de todos. Aqui estão as diretrizes caso você queira nos ajudar:
Contribuições

As contribuições para as dependências do projeto devem ser feitas na forma de *pull requests* no GitHub. Cada *pull request* será analisado por um colaborador principal (alguém com permissão para integrar alterações) e, então, será integrado à *branch* principal ou receberá *feedback* sobre as alterações necessárias. Todas as contribuições devem seguir este formato, inclusive as feitas por colaboradores principais.

Caso queira trabalhar em uma *issue* (tarefa/problema), por favor, manifeste seu interesse primeiro comentando na *issue* do GitHub em questão. Isso evita a duplicação de esforços por parte de diferentes colaboradores na mesma tarefa.
Lista de verificação para *Pull Requests*

    Crie uma *branch* a partir da *branch* `master` e, se necessário, faça um *rebase* para a versão atual da *branch* `master` antes de enviar seu *pull request*. Se a integração com a `master` não ocorrer sem conflitos, pode ser solicitado que você faça um *rebase* das suas alterações.

    Os *commits* devem ser o menor possível, garantindo que cada um deles esteja correto de forma independente (ou seja, cada *commit* deve compilar e passar nos testes).

    Os *commits* devem incluir uma assinatura do *Developer Certificate of Origin* (http://developercertificate.org), indicando que você (e seu empregador, se aplicável) concorda em se sujeitar aos termos da licença do projeto. No Git, isso é feito utilizando a opção `-s` no comando `git commit`.

    Se o seu *patch* não estiver sendo analisado ou se você precisar que uma pessoa específica o analise, você pode mencionar um revisor (usando `@`) no *pull request* ou em um comentário para solicitar a revisão.

    Adicione testes relevantes para o *bug* corrigido ou para a nova funcionalidade.

Para instruções específicas sobre o Git, consulte o guia básico de fluxo de trabalho do GitHub (*GitHub workflow 101*).
