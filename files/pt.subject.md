# CUB3D

# Prefácio

Desenvolvido pela Id Software pelos famosos John Carmack e John Romero, publicado em 1992 pela Apogee Software, Wolfenstein 3D é o primeiro verdadeiro “First Person Shooter” na história dos videojogos.

Wolfenstein 3D é o antepassado de jogos como Doom (Id Software, 1993), Doom II (Id Software, 1994), Duke Nukem 3D (3D Realm, 1996) e Quake (Id Software, 1996), que são outros marcos eternos no mundo dos videojogos.

Agora, é a tua vez de reviver a História...

## NOTA: 
	O jogo Wolfenstein 3D passa-se originalmente na Alemanha nazi, o que pode ser eventualmente perturbador. As imagens e a história deste jogo só vos são apresentadas por razões técnicas e de cultura pop/geek, uma vez que o jogo foi considerado uma obra-prima para ambos.

# Objectivos

Os objectivos deste projeto são semelhantes a todos os objectivos deste primeiro ano: Rigor, utilização de C, utilização de algoritmos básicos, pesquisa de informação, etc.

Como projeto de design gráfico, o cub3D vai permitir-lhe melhorar as suas competências nestas áreas: janelas, cores, eventos, formas de preenchimento, etc.

Em suma, o cub3D é um espaço de jogo notável para explorar as aplicações práticas e lúdicas da matemática sem ter de compreender as suas especificidades.

Com a ajuda dos numerosos documentos disponíveis na Internet, utilizarás a matemática como uma ferramenta para criar algoritmos elegantes e eficientes.

# Parte obrigatória - cub3D

Nome do programa: cub3D
Entregue os ficheiros: Todos os seus ficheiros
Makefile: all, clean, fclean, re, bonus
Argumentos: um mapa no formato *.cub
Funções externas.
- open, close, read, write, printf, malloc, free, perror, strerror, exit, gettimeofday
- Todas as funções da biblioteca de matemática (-lm man man 3 math)
- Todas as funções da biblioteca MinilibX
autorizadas: Sim
Descrição: Tens de criar uma representação gráfica 3D “realista” do interior de um labirinto a partir de uma perspetiva na primeira pessoa. Tens de criar esta representação usando os princípios de Ray-Casting mencionados anteriormente.

## As restrições são as seguintes:

- É necessário utilizar a miniLibX. Ou a versão que está disponível no sistema operativo, ou a partir dos seus fontes. Se optar por trabalhar com os fontes, terá de aplicar as mesmas regras para a sua libft que as escritas acima na parte das Instruções Comuns.

- A gestão da sua janela deve ser simples: mudar para outra janela, minimizar, etc.

- Apresenta diferentes texturas de parede (a escolha é tua) que variam consoante o lado para o qual a parede está virada (Norte, Sul, Este, Oeste).

- O seu programa deve ser capaz de definir as cores do chão e do teto para duas cores diferentes.

- O programa mostra a imagem numa janela e respeita as seguintes regras:

	◦ As teclas de seta esquerda e direita do teclado devem permitir olhar para a esquerda e para a direita no labirinto.
	◦ As teclas W, A, S e D devem permitir mover o ponto de vista através do labirinto.
	◦ Pressionar ESC deve fechar a janela e sair do programa de forma limpa.
	◦ Clicar na cruz vermelha na moldura da janela deve fechar a janela e sair do programa de forma limpa.
	◦ Recomenda-se vivamente a utilização de imagens do minilibX.

- O programa deve receber como primeiro argumento um ficheiro de descrição de cena com a extensão .cub.

O mapa deve ser composto apenas por 6 caracteres possíveis: 0 para um espaço vazio, 1 para uma parede, e N,S,E ou W para a posição inicial do jogador e a orientação do spawn.

## Este é um mapa simples e válido:
```
111111
100101
101001
1100N1
111111
```

◦ O mapa tem de ser fechado/cercado por paredes, caso contrário o programa deve devolver um erro.

◦ Exceto para o conteúdo do mapa, cada tipo de elemento pode ser separado por uma ou mais linhas vazias.

◦ Com exceção do conteúdo do mapa, que tem de ser sempre o último, cada tipo de elemento pode ser definido por qualquer ordem no ficheiro.

◦ Exceto no caso do mapa, cada tipo de informação de um elemento pode ser separado por um ou mais espaços.

◦ O mapa deve ser analisado tal como está no ficheiro. Os espaços são uma parte válida do mapa e cabe ao utilizador tratá-los. Deve ser capaz de analisar qualquer tipo de mapa, desde que respeite as regras do mapa.

◦ A primeira informação de cada elemento (exceto o mapa) é o identificador de tipo (composto por um ou dois caracteres), seguido de todas as informações específicas de cada objeto numa ordem rigorosa, como por exemplo :

## Textura do Norte:

NO ./path_to_the_north_texture
· identificador: NO
· caminho para o texto norte

## Textura do Sul:

NO ./path_to_the_south_texture
· identificador: SO
· caminho para o texto sul

## Textura do Oeste:

NO ./path_to_the_west_texture
· identificador: WE
· caminho para o texto oeste

## Textura do Leste:

NO ./path_to_the_east_texture
· identificador: LA
· caminho para o texto leste

## Cor do pavimento:

F 220,100,0
· identificador: F
· R,G,B cores na gama [0,255]: 0, 255, 255

## Cor do teto:

C 220,30,0
· identificador: C
· R,G,B cores na gama [0,255]: 0, 255, 255

◦ Exemplo da parte obrigatória com uma cena minimalista .cub:

```NO ./path_to_the_north_texture
SO ./path_to_the_south_texture
WE ./path_to_the_west_texture
EA ./path_to_the_east_texture
F 220,100,0
C 225,30,0
1111111111111111111111111
1000000000110000000000001
1011000001110000000000001
1001000000000000000000001
111111111011000001110000000000001
100000000011000001110111111111111
11110111111111011100000010001
11110111111111011101010010001
11000000110101011100000010001
10000000000000001100000010001
10000000000000001101010010001
11000001110101011111011110N0111
11110111 1110101 101111010001
11111111 1111111 111111111111
```

Se for encontrada qualquer configuração incorrecta de qualquer tipo no ficheiro, o programa deve sair corretamente e devolver “Error\n” seguido de uma mensagem de erro explícita à sua escolha.
