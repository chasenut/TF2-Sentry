<div align="center">

<img src="images/banner.png" alt="banner" height="120">

<br>

<img src="images/raw-sentry.png" alt="sentry" height="450">

<br>
<br>

Team Fortress 2 Sentry (Level 1).<br>
3D print your own and upgrade it!

</div>

<br>

<div align="center">
    
# About

<br>

<img src="images/engie.png" height="400">

</div>

<br>
<br>

I started this project about in February, 2025, after Valve announced open-sourcing Team Fortress 2.<br>
TF2 was (and will be) my favourite shooter, I grew up with it, and I love it. <br>
It always had place in my heart. So here I am, to commit something to the community, I made this project
which includes self-made 3D CADs and some electronics. <br>
This took hundrets of hours to make, and spanned over 4 whole months to make.

<br>

**Feel free to do whatever you want with it!**


## Parts

Microcontroller: `ESP32`<br>
I'm using some standard servos and motors, as well as LEDs etc. <br>
All (electronic) parts can be purchased at [botland.com.pl](https://www.botland.com/pl).<br>
Everything (that could be) is 3D-printed. I made all models myself.<br>
This version of the turret 
**doesn't require any custom metal parts, everything is 3D-printable** 
and screw together using only M3 and M4 machine screws.<br>
All (printable) models should be in `parts/` directory.<br>
<br>

### Needed (store bought) parts

You may need these parts:
- (3) Metal bearings `6004/2RS` (or any other model, only important thing are dimensions)
- (2) Standard servos `MG995` or `MG996R` or any standard servo that fit. **Note here**, I found these
to be a little to weak (and they don't really handle the weight of everything). I recommend finding
a stronger ones with the same dimensions
- (2) Servo horns (metal is recommended), must work with your servo, something like [these](https://www.amazon.com/Honbay-Aluminum-Standard-Airplane-Hop-up/dp/B09CT7QK6C?crid=WCAL3KE6WP6U&dib=eyJ2IjoiMSJ9.A-2tVrSBK_nDhgnajDCaG5DGsGU8gip1h5hMZdfCfaoNNMAw_8MamgDyfK91KMFvMj6VPho9NVWkbNPimfnyfqcgPQRFkAiomSEqtIkB1PLtXui_cWTA1RdbElJmMT3i8EtclouQ_pIGN6_l6Lhw8wcJ0IQVeYJgY5GnGMEPaH6VtXl4ZjJhnpnU4ZG2uEUrk8VtgCBuX2hm0KUHKwY6XCCg22L0k-tTK_NkgGbvNG5lhfWTNKrkHJwSflT3Ae2zC6eU6udb1uIK3wzfYoPlvqsKLao6ZOYjhcL67UT3iaU.9IQazK-aj2yUZB9hqG4oNidF6vLXv6WUXb6kGpgxRic&dib_tag=se&keywords=servo+horn+20+%2F+6+mm&qid=1753796789&sprefix=servo+horn+20+%2F+6+mm%2Caps%2C177&sr=8-13)
- (A lot of) `M3` and `M4` machine screws of different lengths, preferebly `10, 15, 20, 30 [mm]`
- (2) Red 8mm LED diodes
- (1) Red 6mm Laser diode (like [this](https://www.amazon.com/HiLetgo-10pcs-650nm-Diode-Laser/dp/B071FT9HSV?crid=I7GCL8QJF65E&dib=eyJ2IjoiMSJ9.oI2MaUtq_e6bIAN-stQQ6MpfkArZMKvMMyaTLe4DPOWmqldbd-1Ed5jJIV3UTFiZvKwOuT1QRX6LFjAFsDho7O2Vlj2jHJRfTfpYsniOcJ7q8T1NJ3vwnsS-bj2Go51U9_6kVivCi161lW1SJxBbAg9r702PjOPZKsiYIrlL9qeAvNRW__q8Ltua7bgz87Sca4RJCS8RLtenxA0UZNhKGwo-TLR_0batNQ9TT4AmmdY.dSE4W3zyhzygTWF7wGBaElauxP8hl-chF1PZsyS41bo&dib_tag=se&keywords=laser+diode&qid=1753797158&sprefix=laser+diod%2Caps%2C217&sr=8-3))
- (1) Red Siren (**to steal 2 parts nice parts from, **red transparent head** and **reflective dish**), [this one](https://www.amazon.com/Car-Siren-Strobe-Light-Rotation/dp/B0DL5T3F2J?crid=2I0PM5JU6T0HD&dib=eyJ2IjoiMSJ9.3hAB26uZD16MsOISHAF8Ca2vZFnTdxsY570IfQnsKwCsagUQsRixXOaP3FQyBeLIBc02z6B-sxiPEADyUs2nrm5ph7BltDJU0vowaOD2CfqptlJIz4dVnj6ZnRArAmWIpwkovJFfsEu5vlXTJT0l70T6TEa79jO_958RgI1SuUGftbR_rY2wSHeCQ7sEbU9wlTAmR1gLnn7Vdnmp0SDdjzzpnaYWHPaAL-71hQshbqI.bkx8H7eYdxVGO6rXSI1bRWsMVsDpMzkTbYUuP8No4EA&dib_tag=se&keywords=spinning%2Bsiren&qid=1753797231&sprefix=spinning%2Bsiren%2Caps%2C183&sr=8-4&th=1)
- (1) Mini Motor, I used `N20-BT39 micro 1000:1 32RPM - 9V` ([mine here](https://botland.com.pl/silniki-micro-n20-seria-mp-medium-power/12601-silnik-n20-bt39-micro-10001-32rpm-9v-5904422377151.html)) 
but you may use any other of your choice (similar specs, same size), it is for siren to spin.

<br>
Of course you may also need some batteries, wires and other circuit-stuff. I didn't make it that good, 
so you can definetly do better than me.


### Printing & Filaments

I used `Polymaker Polyterra` filament (1.75):
- [Matte Lava Red](https://www.amazon.com/Polymaker-PolyTerra-Bioplastic-Printing-Filament/dp/B08QMDD6NP?crid=3PMWMXBTD0T3W&dib=eyJ2IjoiMSJ9.lKMGJTW1it5_kCn31gLdMzXsdbxuZ99zAYBfou5We3nXALFB7zVIb1xSL15zdYZg0HmRGlI_oArlAv4SOE1OTxA02DEM2BnAcYRqrRD_tGIQ9Zncw4p-kZ6UEpt8gURqhHJS82UVc127mxTlIlLYakHbWmMWlycWG2lgJ1zfBOgJZFLNfXXI5yig4DM8Up-_NXs3RTMUa52fJp0ZYj6NHCv--zKR__Ujpkg1t3ZemwE.BLtRAE_T82XkTypFW1r05cQ0fUHN3-1F4bVwllabef4&dib_tag=se&keywords=polymaker%2Bpolyterra&qid=1753795412&sprefix=polymaker%2Bpolyterr%2Caps%2C219&sr=8-3&th=1)
- [Matte Charcoal Black](https://www.amazon.com/Polymaker-PolyTerra-Bioplastic-Printing-Filament/dp/B08QMBPZBF?crid=3PMWMXBTD0T3W&dib=eyJ2IjoiMSJ9.lKMGJTW1it5_kCn31gLdMzXsdbxuZ99zAYBfou5We3nXALFB7zVIb1xSL15zdYZg0HmRGlI_oArlAv4SOE1OTxA02DEM2BnAcYRqrRD_tGIQ9Zncw4p-kZ6UEpt8gURqhHJS82UVc127mxTlIlLYakHbWmMWlycWG2lgJ1zfBOgJZFLNfXXI5yig4DM8Up-_NXs3RTMUa52fJp0ZYj6NHCv--zKR__Ujpkg1t3ZemwE.BLtRAE_T82XkTypFW1r05cQ0fUHN3-1F4bVwllabef4&dib_tag=se&keywords=polymaker%2Bpolyterra&qid=1753795412&sprefix=polymaker%2Bpolyterr%2Caps%2C219&sr=8-3&th=1)

One spool of `red` filament is enough (1kg), but you may need a few of the `black`s, 
I used about 3-4 (kg) of those.

For **printing** I used `Bambu Lab P1S`, **no need for AMS** module. <br>
Everything is printed on `0.08 mm` layer height, I used default `Bambu Studio` presets.<br>



### Contact

For any additional info and contribution, please contanct me:

***Email***
- `switalamaciej5[at]gmail.com`
- `switalamaciej64[at]gmail.com`

***Discord***
- `cashtan`

***Github***
- `chasenut`

## Some fun specs

This Sentry:
- Has a maximum height of about `55cm` or `21.6"`
- Is heavy (weighs a couple of solid pounds)
- Took a few (whole) days just to print the parts
- Uses many many screws
- Takes about 30-60 minutes just to dis/assemble
- Has a spinning sirent with LED
- Has a front LED and LED Laser
- Is capable of rotation:
    - vertical elevation/depression
    - horizontal traverse
- Has moving parts

<div align="center">

# Gallery

<br>

<img src="images/s1.jpg" width="700">

<br>

<img src="images/s2.jpg" width="700">

</div>

<br>

# Functionality & code

This project's goal was to create a **3D replica** of Sentry from our beloved game Team Fortress 2.
Code for this Sentry _(and wireless module (Wrangler), which is not finished)_ isn't ready or good, 
I would say it is trash and was assembled quickly just to test the turret. **Feel free** to make/submit
your own code for this project, you can use current one as reference. 

# Code build

For building and deploying I use(d) **Visual Studio Code** plugin [Platformio](https://platformio.org/).

---

<div align="center">
    <img src="images/manual.jpg" alt="manual">
</div>

---

## Notice

Inspired by [Mr. Volt](https://www.youtube.com/@MrVolt).

This project is not affiliated with Valve Corporation.
Images sources:
- [teamfortress.com](https://www.teamfortress.com)
- [mundymundy.tumblr.com](https://mundymundy.tumblr.com/post/672858009940213760/hello-can-you-do-general-relationship-headcanons)
