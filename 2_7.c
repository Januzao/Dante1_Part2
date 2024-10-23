#include <stdio.h>

int main(){
   double energja_spozyta;
   double wartosc_netto;
   double wartosc_brutto;
   double Vat;

   Vat = 0.22;

   printf("Podaj ilosc kWh:");
   if(scanf("%lf", &energja_spozyta) !=1 || energja_spozyta < 0){
       printf("incorrect input");
       return 1;
   }
   if (energja_spozyta <= 50) {
       wartosc_netto = energja_spozyta * 0.5;
   }
   else if (energja_spozyta <=150) {
       wartosc_netto = 50 * 0.5 + (energja_spozyta - 50) * 0.75;
   }
   else if (energja_spozyta <= 250) {
       wartosc_netto = 50 * 0.5 + 100 * 0.75 + (energja_spozyta - 150) * 1.20;
   }
   else {
       wartosc_netto = 50 * 0.5 + 100 * 0.75 + 100 * 1.20 + (energja_spozyta - 250) * 1.50;
   }

   wartosc_brutto = wartosc_netto * (1 + Vat);
   printf("Koszt brutto: %.6lf\n", wartosc_brutto);

    return 0;
}