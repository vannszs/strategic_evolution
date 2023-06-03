#include <stdio.h>

#include <stdbool.h>

#include <stdlib.h>

#include <math.h>

#include <string.h>

#include <time.h>

struct Broiler {
  float protein;
  float lemak;
  float serat;
  float kalsium1;
  float kalsium2;
  float fosfor1;
  float fosfor2;
  float em;
};

struct Petelur {
  float protein;
  float lemak1;
  float lemak2;
  float serat;
  float kalsium1;
  float kalsium2;
  float fosfor;
  float em;
};

struct jagung {
  float protein;
  float lemak;
  float serat;
  float kalsium;
  float fosfor;
  float em;
};

struct sorgum {
  float protein;
  float lemak;
  float serat;
  float kalsium;
  float fosfor;
  float em;
};

struct beras {
  float protein;
  float lemak;
  float serat;
  float kalsium;
  float fosfor;
  float em;
};

struct mkepala {
  float protein;
  float lemak;
  float serat;
  float kalsium;
  float fosfor;
  float em;
};

struct Child {
  char id[3];
  char parent_id[3];
  float x1;
  float x2;
  float x3;
  float x4;
  float sigma1;
  float sigma2;
  float sigma3;
  float sigma4;
  float fitness;
};

// INI PENALTY PETELUR

float Penalty_petelur(float x1, float x2, float x3, float x4, struct jagung jagung, struct sorgum sorgum, struct beras beras, struct mkepala mkepala, struct Petelur petelur) {
  float penalty_protein = x1 * jagung.protein + x2 * sorgum.protein + x3 * beras.protein + x4 * mkepala.protein;
  float penalty_lemak = x1 * jagung.lemak + x2 * sorgum.lemak + x3 * beras.lemak + x4 * mkepala.lemak;
  float penalty_serat = x1 * jagung.serat + x2 * sorgum.serat + x3 * beras.serat + x4 * mkepala.serat;
  float penalty_kalsium = x1 * jagung.kalsium + x2 * sorgum.kalsium + x3 * beras.kalsium + x4 * mkepala.kalsium;
  float penalty_fosfor = x1 * jagung.fosfor + x2 * sorgum.fosfor + x3 * beras.fosfor + x4 * mkepala.fosfor;
  float penalty_em = x1 * jagung.em + x2 * sorgum.em + x3 * beras.em + x4 * mkepala.em;
  petelur.protein;
  if (penalty_protein != petelur.protein) {
  penalty_protein = fabs(petelur.protein - penalty_protein);
} else {
  penalty_protein = 0;
}

if(penalty_lemak < petelur.lemak1)
{
    penalty_lemak = fabs(petelur.lemak1 < penalty_lemak);
}else if(penalty_lemak > petelur.lemak2)
{
    penalty_lemak = fabs(petelur.lemak2 - penalty_lemak);
}else{
    penalty_lemak = 0;
}

if (penalty_serat > petelur.serat) {
  penalty_serat = fabs(petelur.serat - penalty_serat);
} else {
  penalty_serat = 0;
}

if (penalty_kalsium < petelur.kalsium1) {
  penalty_kalsium = fabs(petelur.kalsium1 - penalty_kalsium);
} else if (penalty_kalsium > petelur.kalsium2) {
  penalty_kalsium = fabs(petelur.kalsium2 - penalty_kalsium);
} else {
  penalty_kalsium = 0;
}

if (penalty_fosfor < petelur.fosfor) {
  penalty_fosfor = fabs(petelur.fosfor - penalty_fosfor);
} else {
  penalty_fosfor = 0;
}


  float total_penalty = penalty_protein + penalty_lemak + penalty_serat + penalty_kalsium + penalty_fosfor + penalty_em;
  float satu = 1.00;
  float hasil = pow(total_penalty, -1);
  return hasil;
}

// INI PENALTY BROILER ##################################################

float Penalty_daging(float x1, float x2, float x3, float x4, struct jagung jagung, struct sorgum sorgum, struct beras beras, struct mkepala mkepala, struct Broiler broiler) {
  float penalty_protein = x1 * jagung.protein + x2 * sorgum.protein + x3 * beras.protein + x4 * mkepala.protein;
  float penalty_lemak = x1 * jagung.lemak + x2 * sorgum.lemak + x3 * beras.lemak + x4 * mkepala.lemak;
  float penalty_serat = x1 * jagung.serat + x2 * sorgum.serat + x3 * beras.serat + x4 * mkepala.serat;
  float penalty_kalsium = x1 * jagung.kalsium + x2 * sorgum.kalsium + x3 * beras.kalsium + x4 * mkepala.kalsium;
  float penalty_fosfor = x1 * jagung.fosfor + x2 * sorgum.fosfor + x3 * beras.fosfor + x4 * mkepala.fosfor;
  float penalty_em = x1 * jagung.em + x2 * sorgum.em + x3 * beras.em + x4 * mkepala.em;
  broiler.protein;
  if (penalty_protein < broiler.protein) {
    penalty_protein = fabs(broiler.protein - penalty_protein);
  } else {
    penalty_protein = 0;
  }

  if (penalty_em < broiler.em) {
    penalty_em = fabs(broiler.em - penalty_em);
  } else {
    penalty_em = 0;
  }

  if (penalty_lemak > broiler.lemak) {
    penalty_lemak = fabs(broiler.lemak - penalty_lemak);
  } else {
    penalty_lemak = 0;
  }

  if (penalty_serat > broiler.serat) {
    penalty_serat = fabs(broiler.serat - penalty_serat);
  } else {
    penalty_serat = 0;
  }

  if (penalty_kalsium < broiler.kalsium1) {
    penalty_kalsium = fabs(broiler.kalsium1 - penalty_kalsium);
  } else if (penalty_kalsium > broiler.kalsium2) {
    penalty_kalsium = fabs(broiler.kalsium2 - penalty_kalsium);
  } else {
    penalty_kalsium = 0;
  }

  if (penalty_fosfor < broiler.fosfor1) {
    penalty_fosfor = fabs(broiler.fosfor1 - penalty_fosfor);
  } else if (penalty_fosfor > broiler.fosfor2) {
    penalty_fosfor = fabs(broiler.fosfor2 - penalty_fosfor);
  } else {
    penalty_fosfor = 0;
  }

  float total_penalty = penalty_protein + penalty_lemak + penalty_serat + penalty_kalsium + penalty_fosfor + penalty_em;
  float satu = 1.00;
  float hasil = pow(total_penalty, -1);

  return hasil;
}
int compare_fitness(const void * a,
  const void * b) {
  float fa = * ((float * )((float * ) a + 9));
  float fb = * ((float * )((float * ) b + 9));
  if (fa < fb) return 1; // Urutkan secara descending
  if (fa > fb) return -1;
  return 0;
}
// INI UNTUK MENGHITUNG NILAI X

float * hitung_x(float * parent, float * sigma) {
  float * child_x = malloc(4 * sizeof(float));

  for (int i = 0; i < 4; i++) {
    float r1 = (float) rand() / RAND_MAX;
    float r2 = (float) rand() / RAND_MAX;
    float N = sqrt(-2 * log(r1)) * sin(2 * M_PI * r2);
    float x = parent[i] + sigma[i] * N;

    if (x < 0) {
      x = fabs(x);
    }
    x = fmaxf(fminf(x, 10), 0.0);

    child_x[i] = x;
  }

  return child_x;
}

// PROGRAM UTAMA MULAI

int main() {

  int jenis, generasi, metode, jumlah_child, jumlah_parent;
  printf("Masukan Jumlah Parent : ");
  scanf(" %d", & jumlah_parent);
  printf("Masukan Jumlah Child Per parent : ");
  scanf(" %d", & jumlah_child);
  printf("Masukan Jumlah Generasi : ");
  scanf(" %d", & generasi);
  float parent_utama[100];

  do {
    printf("\nSilahkan pilih jenis ayam\n1. Broiler Finisher\n2. Petelur Finisher\nMasukkan angka: ");
    scanf("%d", & jenis);
  } while (jenis > 2);

  bool loop = false;
  struct Broiler broiler = {
    18,
    8,
    6,
    0.90,
    1.20,
    0.60,
    1,
    2900
  };
  struct Petelur petelur = {
    18,
    3.5,
    3.7,
    7,
    3.25,
    4,
    0.40,
    2750
  };
  struct jagung jagung = {
    8.6,
    3.9,
    2,
    0.09,
    0.3,
    3370
  };
  struct sorgum sorgum = {
    10,
    2.8,
    2,
    0.4,
    2.13,
    3250
  };
  struct beras beras = {
    8,
    1.7,
    9,
    0.09,
    0.08,
    2660
  };
  struct mkepala mkepala = {
    14.1,
    8.12,
    23.32,
    0.29,
    0.79,
    1450
  };
  float parent[9];
  float best_child[11];
  float child[jumlah_parent * jumlah_child][11];
  //   float best_child[jumlah_parent][11];

  float best_child_per_parent[jumlah_parent][11];
    srand(time(NULL));
    for (int j = 0; j < jumlah_parent; j++) {
      // Mengisi array parent dengan bilangan acak antara 0 dan 1
      for (int k = 0; k < 9; k++) {
        parent[j * 9 + k] = (float) rand() / RAND_MAX;
      }
      // Menyalin nilai-nilai dari array parent ke array parent_utama
      for (int k = 0; k < 9; k++) {
        parent_utama[j * 9 + k] = parent[j * 9 + k];
      }
    }
  // LOOPING GENERASIIIIII
  for (int i = 0; i < generasi; ++i) {

    
      if (jenis == 1 && loop == false) {
        parent[8] = Penalty_daging(
          parent[0],
          parent[1],
          parent[2],
          parent[3],
          jagung, sorgum, beras, mkepala, broiler
        );
      } else if (jenis == 2 && loop == false) {
        parent[8] = Penalty_petelur(
          parent[0],
          parent[1],
          parent[2],
          parent[3],
          jagung, sorgum, beras, mkepala, petelur
        );
      } else {
        for (int i = 0; i < jumlah_parent; i++) {
          for (int j = 0; j < 9; j++) {
            parent[j] = parent_utama[i * 9 + j];
          }
          for (int j = 0; j < 9; j++) {
            best_child[j] = best_child_per_parent[i][j];
          }

          parent[0] = best_child[2]; // ubah nilai x1
          parent[1] = best_child[3]; // ubah nilai x2
          parent[2] = best_child[4]; // ubah nilai x3
          parent[3] = best_child[5]; // ubah nilai x4
          parent[4] = best_child[6]; // ubah nilai sigma1
          parent[5] = best_child[7]; // ubah nilai sigma2
          parent[6] = best_child[8]; // ubah nilai sigma3
          parent[7] = best_child[9]; // ubah nilai sigma4
          parent[8] = best_child[10]; // ubah nilai fitness

          // Lakukan operasi atau manipulasi selanjutnya dengan variabel parent
        }

      }
    
  


    int childNum = 0;

    for (int i = 0; i < jumlah_parent; i++) {
      float * parent = & parent_utama[i * 9];

      for (int j = 0; j < jumlah_child; j++) {
        // Hitung x dan sigma untuk child

        // Mengisi child_x dengan nilai x1 hingga x4 yang sama dengan parent
        float sigma_values[4];
        for (int k = 0; k < 4; k++) {
          sigma_values[k] = parent[k + 4];
        }

        float child_x[4];
        for (int k = 0; k < 4; k++) {
          child_x[k] = parent[k];
        }

        // Calculate child_x using hitung_x
        float * computed_child_x = hitung_x(child_x, sigma_values);
        for (int k = 0; k < 4; k++) {
          child_x[k] = computed_child_x[k];
        }
        float child_fitness;
    if (jenis == 1) {
      child_fitness = Penalty_daging(
        computed_child_x[0],
        computed_child_x[1],
        computed_child_x[2],
        computed_child_x[3],
        jagung, sorgum, beras, mkepala, broiler
      );
    } else {
      child_fitness = Penalty_petelur(
        computed_child_x[0],
        computed_child_x[1],
        computed_child_x[2],
        computed_child_x[3],
        jagung, sorgum, beras, mkepala, petelur
      );
    }

        // Hitung sigma untuk child berdasarkan fitness
        float * new_sigma = malloc(sizeof(float) * 4);
        for (int k = 0; k < 4; k++) {
          if (child_fitness < parent[8]) {
            new_sigma[k] = sigma_values[k] * 0.9;
          } else {
            new_sigma[k] = sigma_values[k] * 1.1;
          }
        }

        // Simpan child ke dalam array child
        child[childNum][0] = j + 1;
        child[childNum][1] = i + 1;

        child[childNum][2] = child_x[0];
        child[childNum][3] = child_x[1];
        child[childNum][4] = child_x[2];
        child[childNum][5] = child_x[3];

        child[childNum][6] = new_sigma[0];
        child[childNum][7] = new_sigma[1];
        child[childNum][8] = new_sigma[2];
        child[childNum][9] = new_sigma[3];

        child[childNum][10] = child_fitness;

        childNum++;

        // Bebaskan memory yang dialokasikan
        free(computed_child_x);
        free(new_sigma);
      }
    }
  
//   printf("Tabel Parent Utama:\n");
//   printf("Parent\t x1\t x2\t x3\t x4\tsigma1\tsigma2\tsigma3\tsigma4\tFitness\n");
//   for (int i = 0; i < jumlah_parent; i++) {
//     printf("P%d\t%.4f\t%.4f\t%.4f\t%.4f\t%.4f\t%.4f\t%.4f\t%.4f\t%.4f\n",
//       i + 1,
//       parent_utama[i * 9 + 0], parent_utama[i * 9 + 1], parent_utama[i * 9 + 2],
//       parent_utama[i * 9 + 3], parent_utama[i * 9 + 4], parent_utama[i * 9 + 5],
//       parent_utama[i * 9 + 6], parent_utama[i * 9 + 7], parent_utama[i * 9 + 8]);
//   }

//   printf("Tabel Child\n");
//   printf("Child\tParent\tx1\tx2\tx3\tx4\tsigma1\tsigma2\tsigma3\tsigma4\tfitness\n");
//   for (int i = 0; i < jumlah_parent; i++) {
//     for (int j = 0; j < jumlah_child; j++) {
//       int childNum = i * jumlah_child + j;

//       printf("C%d\tP%d\t", childNum + 1, i + 1);
//       printf("%.4f\t%.4f\t%.4f\t%.4f\t", child[childNum][2], child[childNum][3], child[childNum][4], child[childNum][5]);
//       printf("%.4f\t%.4f\t%.4f\t%.4f\t", child[childNum][6], child[childNum][7], child[childNum][8], child[childNum][9]);
//       printf("%.4f\n", child[childNum][10]);
//     }
//   }


// Menginisialisasi array best_child_per_parent dengan nilai awal yang valid
for (int i = 0; i < jumlah_parent; i++) {
  for (int j = 0; j < 11; j++) {
    best_child_per_parent[i][j] = child[i * jumlah_child][j];
  }
}

// Memilih child terbaik dari setiap parent
for (int i = 0; i < jumlah_parent; i++) {
  for (int j = 1; j < jumlah_child; j++) {
    int childNum = i * jumlah_child + j;

    if (child[childNum][10] > best_child_per_parent[i][10]) {
      for (int k = 0; k < 11; k++) {
        best_child_per_parent[i][k] = child[childNum][k];
      }
    }
  }
}

// Memindahkan array best_child ke array parent_utama
for (int i = 0; i < jumlah_parent; i++) {
  parent_utama[i * 9 + 0] = best_child_per_parent[i][2];
  parent_utama[i * 9 + 1] = best_child_per_parent[i][3];
  parent_utama[i * 9 + 2] = best_child_per_parent[i][4];
  parent_utama[i * 9 + 3] = best_child_per_parent[i][5];
  parent_utama[i * 9 + 4] = best_child_per_parent[i][6];
  parent_utama[i * 9 + 5] = best_child_per_parent[i][7];
  parent_utama[i * 9 + 6] = best_child_per_parent[i][8];
  parent_utama[i * 9 + 7] = best_child_per_parent[i][9];
  parent_utama[i * 9 + 8] = best_child_per_parent[i][10];
}



  }// ini tag untuk looping generasi
// PRINT SETELAH INI
// Sortir array best_child_per_parent berdasarkan nilai fitness secara menurun
for (int i = 0; i < jumlah_parent - 1; i++) {
  for (int j = 0; j < jumlah_parent - i - 1; j++) {
    if (best_child_per_parent[j][10] < best_child_per_parent[j + 1][10]) {
      // Tukar posisi
      for (int k = 0; k < 11; k++) {
        float temp = best_child_per_parent[j][k];
        best_child_per_parent[j][k] = best_child_per_parent[j + 1][k];
        best_child_per_parent[j + 1][k] = temp;
      }
    }
  }
}

// Cetak tabel "Best Child Per Parent" setelah pengurutan
printf("Best Child Per Parent Setelah %d generasi (diurutkan berdasarkan fitness)\n", generasi);
printf("Child\tParent\tx1\tx2\tx3\tx4\tsigma1\tsigma2\tsigma3\tsigma4\tfitness\n");

for (int i = 0; i < jumlah_parent; i++) {
  int parentIndex = i + 1;
  int bestChildIndex = best_child_per_parent[i][0]; // Mengambil index child terbaik dari parent
  printf("C%d\t", bestChildIndex);
  printf("P%d\t", parentIndex);

  for (int j = 2; j < 10; j++) {
    printf("%.4f\t", best_child_per_parent[i][j]);
  }

  printf("%.4f\n", best_child_per_parent[i][10]);
}


}
 



//
