/* --------------------------------o---x---o--------------------------------
2 * lista.h declaración y primitivas del TDA LISTA
3 * implementada en lista dinámica simplemente enlazada
4 * --------------------------------o---x---o-------------------------------- */
5
6 #ifndef LISTA_H_
7 #define LISTA_H_
8
9
10 #include <stdlib.h>
11 #include <string.h>
12
13
14 #define SIN_MEM 1
15 #define CLA_DUP 2
16 #define TODO_BIEN 0
17
18
19 typedef struct sNodo
20 {
21 void *info;
22 unsigned tamInfo;
23 struct sNodo *sig;
24 } tNodo;
25 typedef tNodo *tLista;
26
27
28 void crearLista(tLista *p);
29
30 int listaVacia(const tLista *p);
31
32 int listaLlena(const tLista *p, unsigned cantBytes);
33
34 void vaciarLista(tLista *p);
35
36 int ponerAlComienzo(tLista *p, const void *d, unsigned cantBytes);
37
38 int sacarPrimeroLista(tLista *p, void *d, unsigned cantBytes);
39
40 int verPrimeroLista(const tLista *p, void *d, unsigned cantBytes);
41
42 int ponerAlFinal(tLista *p, const void *d, unsigned cantBytes);
43
44 int sacarUltimoLista(tLista *p, void *d, unsigned cantBytes);
45
46 int verUltimoLista(const tLista *p, void *d, unsigned cantBytes);
47
48
49 #endif // LISTA_H_
50
51
52 /* --------------------------------o---x---o-------------------------------- */
53
54 /* --------------------------------o---x---o--------------------------------
55 * lista.c definición y primitivas del TDA LISTA
56 * implementada en lista dinámica simplemente enlazada
57 * --------------------------------o---x---o-------------------------------- */
58
59 #include "lista.h"
60
61
62 #define minimo( X , Y ) ( ( X ) <= ( Y ) ? ( X ) : ( Y ) )
63
64
65 void crearLista(tLista *p)
66 {
67 *p = NULL;
68 }
69
70
71 int listaVacia(const tLista *p)
72 {
73 return *p == NULL;
74 }
75
76
77 int listaLlena(const tLista *p, unsigned cantBytes)
78 {
79 tNodo *aux = (tNodo *)malloc(sizeof(tNodo));
80 void *info = malloc(cantBytes);
81
82 free(aux);
83 free(info);
84 return aux == NULL || info == NULL;
85 }
86
87
88 void vaciarLista(tLista *p)
89 {
90 while(*p)
91 {
92 tNodo *aux = *p;
93
94 *p = aux->sig;
95 free(aux->info);
96 free(aux);
97 }
98 }
99
100
101 int ponerAlComienzo(tLista *p, const void *d, unsigned cantBytes)
102 {
103 tNodo *nue;
104
105 if((nue = (tNodo *)malloc(sizeof(tNodo))) == NULL ||
106 (nue->info = malloc(cantBytes)) == NULL)
107 {
108 free(nue);
109 return 0;
110 }
111 memcpy(nue->info, d, cantBytes);
112 nue->tamInfo = cantBytes;
113 nue->sig = *p;
114 *p = nue;
115 return 1;
116 }
117
118
119 int sacarPrimeroLista(tLista *p, void *d, unsigned cantBytes)
120 {
121 tNodo *aux = *p;
122
123 if(aux == NULL)
124 return 0;
125 *p = aux->sig;
126 memcpy(d, aux->info, minimo(cantBytes, aux->tamInfo));
127 free(aux->info);
128 free(aux);
129 return 1;
130 }
131
132
133 int verPrimeroLista(const tLista *p, void *d, unsigned cantBytes)
134 {
135 if(*p == NULL)
136 return 0;
137 memcpy(d, (*p)->info, minimo(cantBytes, (*p)->tamInfo));
138 return 1;
139 }
140
141
142 int ponerAlFinal(tLista *p, const void *d, unsigned cantBytes)
143 {
144 tNodo *nue;
145
146 while(*p)
147 p = &(*p)->sig;
148 if((nue = (tNodo *)malloc(sizeof(tNodo))) == NULL ||
149 (nue->info = malloc(cantBytes)) == NULL)
150 {
151 free(nue);
152 return 0;
153 }
154 memcpy(nue->info, d, cantBytes);
155 nue->tamInfo = cantBytes;
156 nue->sig = NULL;
157 *p = nue;
158 return 1;
159 }
160
161
162 int sacarUltimoLista(tLista *p, void *d, unsigned cantBytes)
163 {
164 if(*p == NULL)
165 return 0;
166 while((*p)->sig)
167 p = &(*p)->sig;
168 memcpy(d, (*p)->info, minimo(cantBytes, (*p)->tamInfo));
169 free((*p)->info);
170 free(*p);
171 *p = NULL;
172 return 1;
173 }
174
175
176 int verUltimoLista(const tLista *p, void *d, unsigned cantBytes)
177 {
178 if(*p == NULL)
179 return 0;
180 while((*p)->sig)
181 p = &(*p)->sig;
182 memcpy(d, (*p)->info, minimo(cantBytes, (*p)->tamInfo));
183 return 1;
184 }
185
186
187 /* --------------------------------o---x---o-------------------------------- */
188
189 /* --------------------------------o---x---o--------------------------------
190 * main.h prueba del TDA LISTA con asignación dinámica de memoria
191 * --------------------------------o---x---o-------------------------------- */
192
193 #ifndef MAIN_H_
194 #define MAIN_H_
195
196 #include <stdio.h>
197
198
199 #include "../../productos/productos.h"
200 #include "../../lineasDeTexto/lineasTexto.h"
201 #include "../../lista/lista.h"
202
203
204 void probarIngresarYMostrarProd(void);
205
206 void probarIngresarYMostrarTexto(void);
207
208 void probarPonerYSacarDeLista(void);
209
210
211 #endif // MAIN_H_
212
213
214 /* --------------------------------o---x---o-------------------------------- */
215
216 /* --------------------------------o---x---o--------------------------------
217 * main.c prueba del TDA LISTA con asignación dinámica de memoria
218 * --------------------------------o---x---o-------------------------------- */
219
220 #include "main.h"
221
222
223 int main(void)
224 {
225 probarIngresarYMostrarProd();
226
227 probarIngresarYMostrarTexto();
228
229 probarPonerYSacarDeLista();
230
231 return 0;
232 }
233
234
235 void probarIngresarYMostrarProd(void)
236 {
237 tProd prod;
238 int cant = 0;
239
240 puts("Probando ingresar productos y mostrar productos.\n"
241 "======== ======== ========= = ======= =========");
242 if(ingresarProducto(&prod))
243 mostrarProducto(NULL);
244 do
245 {
246 mostrarProducto(&prod);
247 cant++;
248 } while(ingresarProducto(&prod));
249 fprintf(stdout, "Se mostraron %d productos.\n\n", cant);
250 }
251
252 void probarIngresarYMostrarTexto(void)
253 {
254 char linea[90];
255 int cant = 0;
256
257 puts("Probando ingresar lineas de texto mostrandolas.\n"
258 "======== ======== ====== == ===== ============");
259 while(ingresarTexto(linea, sizeof(linea)))
260 {
261 cant++;
262 printf("\"%s\"\n", linea);
263 }
264 fprintf(stdout, "Se mostraron %d lineas de texto.\n\n", cant);
265 }
266
267
268
269
270 void probarPonerYSacarDeLista(void)
271 {
272 tLista lista;
273
274 crearLista(&lista);
275 if(listaLlena(&lista, 1))
276 puts("Que pasa? No hay lugar ni para un Byte? No hay memoria???");
277 if(listaVacia(&lista))
278 puts("Obviamente que la lista esta vacia! Recien creada!");
279 vaciarLista(&lista);
280 }
281
282
283 /* --------------------------------o---x---o-------------------------------- */
