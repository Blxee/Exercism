#include "rna_transcription.h"
#include <stdlib.h>

char *ft_strdup(const char *const str)
{
  int len;
  char *dup;
  int i;

  len = 0;
  while (str[len])
    len++;
  dup = malloc(len + 1);
  i = 0;
  while (i < len)
  {
    dup[i] = str[i];
    i++;
  }
  dup[i] = '\0';
  return (dup);
}

char *to_rna(const char *dna)
{
  const char *const MAP_KEYS = "GCTA";
  const char *const MAP_VALS = "CGAU";
  char *rna;
  int i;
  int j;

  rna = ft_strdup(dna);
  i = 0;
  while (rna[i])
  {
    j = 0;
    while (MAP_KEYS[j] && MAP_KEYS[j] != rna[i])
      j++;
    rna[i] = MAP_VALS[j];
    i++;
  }
  return (rna);
}
