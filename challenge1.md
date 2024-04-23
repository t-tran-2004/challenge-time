# Residential Computer Sales

This challenge focuses on the maximum subarray problem. A state-renowned residential computer company shares the revenue dataset for the 2023 Fiscal Year.

| _Month_ | _Sales (USD)_ | _Profit/Loss_ |
| :-----: | :-----------: | :-----------: |
| Jan 2023 | $100M | N/A |
| Feb 2023 | $113M | +$13M (+13.00%) |
| Mar 2023 | $110M | -$3M (-2.65%) |
| Apr 2023 | $85M | -$25M (-22.73%) |
| May 2023 | $81M | -$4M (-4.71%) |
| Jun 2023 | $101M | +$20M (+24.69%) |
| Jul 2023 | $94M | -$7M (-6.93%) |
| Aug 2023 | $106M | +$12M (+12.77%) |
| Sep 2023 | $105M | -$1M (-0.94%) |
| Oct 2023 | $102M | -$3M (-2.86%) |
| Nov 2023 | $86M | -$16M (-15.69%) |
| Dec 2023 | $63M | -$23M (-26.74%) |

Then, an advertising campaign that lasts for three months to boost sales will be effective between June and August 2024, racking up $25 million in potential profits.

```assembly
section .text
	global _start

_start:
	mov eax, start		; retrieve the starting point from p/l array
	mov ecx, 4		; 1 doubleword = 4 bytes
	div ecx			; n bytes = n/4 doublewords
	mov ecx, eax		; number of doublewords from start

	mov eax, 11		; 11 initial entries
	sub eax, ecx		; 11 - (# of doublewords from start) entries
	mov ecx, pl		; get contents of p/l array from index 0

	add ecx, start		; advance by n bytes
	mov ebx, [ecx]		; add to starting term
	dec eax			; counter: eax = eax - 1

	add ecx, 4		; advance by one term (4 bytes)
	add ebx, [ecx]		; add new term to existing term(s)
	dec eax			; counter: eax = eax - 1
	mov [peak], ebx		; initial peak

	jmp comp		; _start --> comp

comp:
	mov edx, [peak]		; move contents in peak variable to edx reg

	add ecx, 4		; advance by one term (4 bytes)
	add ebx, [ecx]		; add new term to existing term(s)

	cmp ebx, edx		; compare ebx to edx (peak)
	jg change		; comp --> change when ebx > edx

	dec eax			; counter: eax = eax - 1
	jnz comp		; comp --> comp when eax ≠ 0
	jmp exit		; comp --> exit

change:
	mov [peak], ebx		; new peak
	dec eax			; counter: eax = eax - 1
	jnz comp		; change --> comp when eax ≠ 0
	jmp exit		; change --> exit

exit:
	xor ebx, ebx		; ebx = 0
	xor ecx, ecx		; ecx = 0
	xor edx, edx		; edx = 0
	mov eax, 1		; SYS_EXIT
	int 0x80		; call kernel

segment .bss
	peak: RESB 1

section .data
	pl DD 13, -3, -25, -4, 20, -7, 12, -1, -3, -16, -23	; p/l array
	start EQU 16						; starting point, number of bytes from p/l array
```
