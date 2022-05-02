# Traffic-Light-Intersection-with-Arduino

Scopul proiectului este acela de a creea un sistem eficient de circulație. Semaforul trebuie plasat judicios pentru a asigura siguranța si rapiditatea atât a mașinilor, cât și a pietonilor. Este importantă sincronizarea semafoarelor in trafic si respectarea ordinii semnalelor luminoase. Semaforul trebuie sa aibă trei lumini (roșu, galben, verde), acestea sa lumineze pe rand, la momentul potrivit si in concordanta cu celelate semafoare din apropiere. Pentru fiecare lumină in parte, se va folosi un LED.
	În momentul în care butonul este apăsat, semaforul pietonilor se pregătește pentru a-și schimba culoarea din roșu în verde. Durează 8 secunde din momentul în care este apăsat butonul și până semaforul de la pieton se face verde.
	Când senzorul IR detectează ambuteiaj (o mașină care staționează în dreptul senzorului când aceasta are verde și ar putea înainta) va amâna momentul de schimbare a culorilor (cu înca 8 secunde)  pentru a mai lăsa timp mașinilor să înainteze.
	Fotorezistorul măsoară cantitatea de lumină și este folosit pentru a detecta atunci când este noapte cu scopul de a face ca semafoarele mașinilor sa lumineze galben intermitent și pe cele de la pietoni să le stingă. Luând în considerare că noaptea nu circulă  atât de mulți oameni precum ziua, aceasta reprezintă o bună metodă de economisire a energiei.

# Placa Intel Galileo
![intel](https://user-images.githubusercontent.com/101409788/166229337-7f09985e-9857-4dbf-859b-8000ec2d4bab.png)

# Macheta
![panorama](https://user-images.githubusercontent.com/101409788/166229441-7f8403b7-b38f-4714-9520-914177edcdef.jpg)

Programul începe in modul de zi, led-urile corespunzătoare sunt aprinse in funcția void loop(), care va continua până la apăsarea butonului. Valoarile butonului, a fotorezistorului și a senzorilor infraroșu sunt constant citite cu un delay de 1 secunda.
 Butonul este citit prin intermediul digitalread() si valoarea sa poate fi 0 sau 1. De fapt se citește valoarea tensiunii de pe rezistorul înseriat cu butonul. Dacă acesta este apăsat, avem cădere de tensiune pe rezistor diferită de 0 si citirea sa digitală este egală cu 1.
 Se intră în primul IF, unde întâi se verifică valoarea analogică primită prin senzorii infraroșu prin analogRead(). Senzorul IR oferă valori intre 0 si 650 pentru o alimentare de 5V, valorile mici indicând prezența unui obiect. Dacă un obiect nu este detectat, se intră imediat in funcția pieton().
După un delay de 8 secunde, pietonii au verde si după alt delay de 7 secunde, se revine in starea inițială în void loop(). Dacă un obiect este detectat, se introduce un delay suplimentar de 8 secunde.
Dacă fotorezistorul detectează întuneric, se intră într-un while loop imbricat, unde semafoarele au galben intermitent. Valoarea fotorezistorului se citește continuu si când aceasta depășește pragul impus, se revine în loop-ul principal.
