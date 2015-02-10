#include <random>
#include <ctime>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

const int k = 5;
const int matkat = 10000;
const int max_aika = 20;

std::vector<int> laske_saapumisajat();
void tulosta_frekvenssi(const std::vector<int> &saapumisajat);
void tulosta_histogrammi(const std::vector<int> &saapumisajat);

int main() {
  auto saapumisajat = laske_saapumisajat();
  tulosta_frekvenssi(saapumisajat); 
  tulosta_histogrammi(saapumisajat);
}

std::vector<int> laske_saapumisajat() {

  std::mt19937_64 gen;
  gen.seed(time(nullptr));
  
  std::uniform_int_distribution<int> odotus(0,5);
  std::uniform_int_distribution<int> matka(10,20 + k);
  
  std::vector<int> saapumisajat;
  
  for (int i = 0; i < matkat; ++i) {
    saapumisajat.push_back(odotus(gen) + matka(gen));
	
  }
  return saapumisajat;
}

void tulosta_frekvenssi(const std::vector<int> &saapumisajat) {
  
  int ehti = 0;
  for (int aika : saapumisajat) {
    if (aika <= max_aika) {
      ++ehti;
    }
	}
  
  std::cout << matkat << " matkalla ehti " << ehti << " kertaa\n";
  std::cout << "Suht. frek: " << ((double)ehti)/matkat << "\n"; 
}


void tulosta_jarjestysluku(int luku);
void tulosta_pylvas(int kpl, int skaalaus) ; 

void tulosta_histogrammi(const std::vector<int> &saapumisajat) {
  const int pylvaita = 40;
  std::vector<int> pylvaat(pylvaita, 0);
 
  for (int i : saapumisajat) {
    pylvaat[i] += 1;
  }
  
  // skaalaustekijä: yksi merkki per 10 matkaa jotka osui kyseiselle ajalle
  const int skaalaus = 40;
  
  std::cout << "\n\nHistogrammi: \n\n";
  
  for (int i = 0; i < pylvaita; ++i) {
    tulosta_jarjestysluku(i);
    std::cout << " ";
    tulosta_pylvas(pylvaat[i], skaalaus);
  }
}

void tulosta_jarjestysluku(int luku) {
  std::cout << luku;
  if (luku < 10) {
    std::cout << " ";
  }
  std::cout << ":";
}

void tulosta_pylvas(int kpl, int skaalaus) {
  const int merkkeja = kpl/skaalaus;
  std::cout << " ";
  for (int i = 0; i < merkkeja; ++i) {
    std::cout << "#";
  }
  
  std::cout << "\n";
}