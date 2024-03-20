#include <stdio.h>
#include <string.h>
int flag;
#define d 256
void naive_search(char* pattern, char* text) {
int m = strlen(pattern);
int n = strlen(text);
int i, j;
flag=1;
for (i = 0; i <= n - m; i++) {
for (j = 0; j < m; j++) {
if (text[i+j] != pattern[j])
break;
}
if (j == m)
{
flag=0;
printf("Pattern found at index %d\n", i);
}
}
}
void rabin_karp_search(char* pattern, char* text, int q) {
int m = strlen(pattern);
int n = strlen(text);
int i, j;
int p = 0; // hash value for pattern
int t = 0; // hash value for current substring of text
int h = 1; // d^(m-1) % q
flag=1;
// calculate h
for (i = 0; i < m - 1; i++)
h = (h * d) % q;
// calculate initial hash values
for (i = 0; i < m; i++) {
p = (d * p + pattern[i]) % q;
t = (d * t + text[i]) % q;
}
// slide the pattern over text one by one
for (i = 0; i <= n - m; i++) {
// check if the hash values of current substring of text and pattern are equal
if (p == t) {
// check if all characters match
for (j = 0; j < m; j++) {
if (text[i+j] != pattern[j])
break;
}
if (j == m)
{
flag=0;
printf("Pattern found at index %d\n", i);
}
}
// calculate hash value for next substring of text
if (i < n - m) {
t = (d * (t - text[i] * h) + text[i+m]) % q;
if (t < 0)
t += q;
}
}
}
int main() {
int choice, q;
char pattern[100], text[100];
while (1) {
printf("\nString Matching Algorithms:\n");
printf("1. Naive String Matching\n");
printf("2. Rabin-Karp Algorithm\n");
printf("3. Exit\n");
printf("Enter your choice: ");
scanf("%d", &choice);
switch (choice) {
case 1:
printf("Enter the text: ");
scanf("%s", text);
printf("Enter the pattern: ");
scanf("%s", pattern);
naive_search(pattern, text);
if(flag==1)
{
printf("No match found\n");
}
break;
case 2:
printf("Enter the text: ");
scanf("%s", text);
printf("Enter the pattern: ");
scanf("%s", pattern);
printf("Enter a prime number: ");
scanf("%d", &q);
rabin_karp_search(pattern, text, q);
if(flag==1)
{
printf("No match found\n");
}
break;
case 3:
printf("Exiting program.\n");
return 0;
default:
printf("Invalid choice. Try again.\n");
}
}
return 0;
}