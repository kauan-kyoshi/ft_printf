# ft_printf — Projeto 42

**Resumo:**
- **Projeto:** reimplementação da função `printf` limitada (subject `ft_printf` da 42).
- **Propósito:** consolidar competências em C (manipulação de argumentos variádicos, recursão, formatação de saída, criação de biblioteca estática e conformidade com a Norminette).

**Como funciona**
- A implementação principal está em `ft_printf.c`. A função percorre a string de formato e, ao encontrar `%`, delega o tratamento para um detector de especificador que chama as rotinas específicas.
- Especificadores suportados: `%c`, `%s`, `%d`, `%i`, `%u`, `%x`, `%X`, `%p`, `%%`.
- Comportamentos especiais:
  - `NULL` em strings é impresso como `(null)`.
  - `NULL` em ponteiros é impresso como `(nil)`.
  - O ponteiro é impresso com o prefixo `0x` em hexadecimal minúsculo.
  - `0` para inteiros sem sinal e hex é impresso como `0`.
  - Caso um `%` seja seguido por um caractere não-implementado, a implementação atual imprime o `%` literal seguido do caractere, sem consumir um argumento — isso evita desalinhamento da lista de argumentos.

**Arquitetura e arquivos importantes**
- `ft_printf.h` — cabeçalho público com as assinaturas.
- `ft_printf.c` — controlador de parsing do formato e dispatch.
- `ft_print_char.c`, `ft_print_string.c`, `ft_print_decimal.c`, `ft_print_unsigned.c`, `ft_print_hex.c`, `ft_print_pointer.c` — módulos que imprimem cada tipo e retornam o número de caracteres escritos.
- `Makefile` — gera a biblioteca estática `libftprintf.a` com `make`.

**Como compilar**
1. Gere os objetos e a biblioteca:
```bash
make
```
2. Para testar rapidamente com um arquivo de exemplo (crie um `test.c` com a chamada a `ft_printf`):
```c
#include "ft_printf.h"

int main(void)
{
    ft_printf("Hello %s, hex: %x, ptr: %p, perc: %%\n", "world", 255, (void *)0);
    return (0);
}
```

Compile e rode:
```bash
gcc test.c libftprintf.a -I. -Ilibft -o test_printf
./test_printf
```

Ou use `gcc your_program.c libftprintf.a -I.` para linkar a biblioteca.

**Exemplos de saída esperada**
- `ft_printf("%c", 'A')` => imprime `A` e retorna `1`.
- `ft_printf("%s", NULL)` => imprime `(null)` e retorna `6`.
- `ft_printf("%p", NULL)` => imprime `(nil)` e retorna `5`.
- `ft_printf("%%")` => imprime `%` e retorna `1`.

**Como testar e validar**
- Executar `make` e compilar um `test.c` simples (exemplo acima).
- Checar retorno da função (número de caracteres) comparando com `printf`.
- Rodar `norminette .` para verificar conformidade de estilo (o repositório foi ajustado para reduzir avisos comuns — ainda assim, execute localmente antes de enviar ao GitHub).

**Competências desenvolvidas**
- Manipulação de argumentos variádicos em C com `stdarg.h` (`va_start`, `va_arg`, `va_end`).
- Escrita de código modular e interfaces claras (separação por ficheiros/capacidades).
- Recursão para conversão de inteiros em base decimal/hexadecimal.
- Tratamento de casos limite (INT_MIN, `NULL`, zero, conversão de ponteiros).
- Construção de biblioteca estática (`ar rcs libftprintf.a` via `Makefile`).
- Adaptação e correção para compatibilidade com a Norminette (estilo 42).
- Debugging de comportamento de formatos e consumo correto dos argumentos.

**Decisões de implementação / Observações**
- Uso de recursão para gerar dígitos: simples e limpo, suficiente para este exercício; em produção, buffers e escrita por blocos podem ser mais eficientes.
- O projeto implementa apenas o subconjunto pedido pelo subject `ft_printf` da 42 — não há suporte para flags (`-`, `0`), largura, precisão, length modifiers (`l`, `h`) nem conversões de ponto flutuante.
- Retorno: todas as funções retornam o total de caracteres escritos (compatível com o comportamento do `printf`).
