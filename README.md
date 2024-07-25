# Smart Electric Socket

## Latar Belakang

![](/img/kota.png)

Berdasarkan data dari Menteri Energi dan Sumber Daya Mineral, konsumsi energi listrik di Indonesia meningkat secara eksponensial dari tahun ke tahun. Pada tahun 2023 konsumsi listrik rata-rata 1.285kWh/kapita. Ini merupakan peningkatan dari 1.173 kWh/kapita pada 2022 (Kementrian ESDM, 2024). Selain itu, hanya 19% energi listrik di Indonesia berasal dari energi terbarukan (renewable energy) dengan sisanya dari batu bara, minyak bumi, dan gas bumi (Madushan, 2024). Oleh karena itu, pentingnya akan efisiensi dan penghematan energi, terutama di era digitalisasi dan keberlanjutan energi. Dengan menggunakan teknologi IoT, kita dapat mengontrol dan memonitor perangkat elektronik di rumah tangga secara efisien.

Perkembangan kewirausahaan di Indonesia juga semakin pesat, kebutuhan bisnis kecil dan menengah (UKM) untuk menghemat biaya operasional sangat penting, khususnya pada penggunaan energi listrik. Terdapat banyak bisnis yang tidak bisa menggunakan seluruh perangkat listriknya secara bersamaan karena kuota daya listrik yang terbatas. Sehingga perlu adanya sistem yang dapat mengatur penggunaan perangkat listrik tersebut secara otomatis.

## Ide Bisnis

![](/img/bisnis.png)

Berdasarkan latar belakang tersebut, kami ingin menyediakan solusi untuk menangani permasalahan mengenai penghematan energi listrik di rumah tangga dan bisnis UKM. Kami membuat sebuah sistem yang dapat mengontrol dan memonitor daya listrik pada perangkat elektronik. Sistem ini akan mengatur penggunaan perangkat listrik secara otomatis berdasarkan kebutuhan pengguna dan juga memberikan informasi mengenai konsumsi daya listrik yang digunakan oleh perangkat elektronik tersebut.

Solusi yang kami tawarkan adalah sebuah produk stop kontak pintar yang dapat dicolok ke stop kontak biasa. Produk ini akan terhubung ke internet dan dapat diakses melalui website. Pengguna dapat mengatur jadwal dan batas penggunaan perangkat listrik, serta memonitor konsumsi daya listrik yang digunakan oleh perangkat elektronik tersebut secara real time. Dengan bentuk yang kecil dan sederhana, produk ini dapat digunakan secara mudah oleh pengguna.

## Deskripsi Perangkat

Smart Stop Kontak adalah sejenis Stop Kontak berbasis IoT dengan berbagai macam fitur unik yang tidak kerap ditemukan pada jenis Stop Kontak secara umum. Smart Stop Kontak juga telah dirancang sedemikian rupa agar penggunanya dapat langsung memakainya dengan mudah. Pengaturan yang tidak rumit dilengkapi dengan fitur yang beraneka ragam membantu mewujudkan keinginan pengguna untuk merealisasikan lingkup IoT idaman yang dapat diintegrasikan pada kehidupan sehari-hari.

## Fitur Perangkat

Adapun beberapa fitur utama yang ditawarkan oleh produk Smart Stop Kontak untuk mewujudkan kegunaan daripada produk itu sendiri, antara lain sebagai berikut:

### Smart Automation

Smart Stop Kontak memungkinkan untuk diimplementasikannya otomatisasi terhadap penggunaan daya listrik pada Stop Kontak itu sendiri. Pengguna dapat mengatur kapan Smart Stop Kontak harus berhenti mengalirkan listrik berdasarkan timer yang telah ditetapkan, ataupun batas penggunaan daya listrik yang telah diatur.

### IoT Connectivity

Pengguna dapat terkoneksi dengan layanan yang disediakan oleh Smart Stop Kontak melalui perantara konektivitas jaringan Wi-Fi. Hal ini memungkinkan akses dari tempat manapun secara instan melalui Web Dashboard yang telah disediakan ataupun melalui layanan Google Home yang telah dipasang pada perangkat Mobile.

### Voice Control

Dengan mengintegrasikan layanan Google Assistant dan Google Home, maka hal ini mampu meningkatkan pengalaman pengguna dalam merasakan betapa mudahnya untuk mengontrol perangkat Smart Stop Kontak melalui fitur Voice Control. Fitur ini memungkinkan pengguna dalam mengatur Smart Stop Kontak hanya dengan perintah suara saja.

### Energy Monitoring

Segala macam bentuk informasi mengenai penggunaan daya Smart Stop Kontak dapat dilihat melalui dashboard dalam bentuk statistik. Pengguna dapat memonitor aktivitas Smart Stop Kontak secara Real-Time dari manapun.

## Rancangan Implementasi Perangkat

![](/img/implementasi.png)

### Implementasi Hardware

![](/img/hardware.png)

Smart Stop Kontak memiliki komponen Hardware yang serupa dengan Stop Kontak pada umumnya, hanya saja ditambahkan perantara tambahan antara Colokan dan Socket, yakni sebuah Relay. Relay tersebut nantinya akan disambungkan dengan sebuah MicroController, seperti ESP32. Relay pada Smart Stop Kontak bertugas sebagai Switch dari Stop Kontak itu sendiri. Dengan mengimplementasikan MicroController pada Relay, maka memungkinkan untuk mengintegrasi IoT agar Smart Stop Kontak dapat dinyalakan sekaligus dimatikan secara otomatis tergantung keinginan penggunanya.

### Immplementasi Microcontroller

![](/img/microcontroller.png)

MicroController pada Smart Stop Kontak berperan sebagai penjembatan antara Software dan Hardware. Pada rancangan Prototype, MicroController yang akan digunakan adalah ESP32. ESP32 akan diprogram sedemikian rupa untuk memenuhi 2 tugas utama, yakni memberikan sinyal ON/OFF pada Relay dan memberikan sinyal MQTT pada Node Red. Isi dari sinyal ON/OFF pada Relay digunakan untuk menyalakan maupun mematikan Smart Stop Kontak, sedangkan isi dari sinyal MQTT pada Node Red memuat data yang akan diolah agar pengguna dapat menggunakan fitur IoT dari Smart Stop Kontak.

### Implementasi Software

![](/img/socket1.png)
![](/img/socket2.png)
![](/img/socket3.png)

Fondasi utama dari segi Software Smart Stop Kontak adalah Framework Node Red. Node Red memungkinkan untuk menerima sinyal MQTT dari MicroController dan mengolahnya agar dapat ditampilkan dalam bentuk dashboard untuk pengguna. Selain itu, Node Red juga dapat diintegrasikan dengan Google Home sekaligus Google Assistant sebagai fitur tambahan dari sisi IoT. Oleh sebab itu, pengguna dapat dengan mudah menggunakan Smartphone-nya untuk mengatur Smart Stop Kontak. Selebihnya, database juga perlu diimplementasikan untuk menyimpan riwayat logging dari data MQTT yang dikirim oleh MicroController.

![](/img/googleAssistant3.png)
![](/img/googleAssistant1.png)
![](/img/googleAssistant2.png)

## Simulasi

### Link Rangkaian

https://wokwi.com/projects/397662154390545409

### Link Video Dashboard

https://youtu.be/rXeNMXtwplE

### Link Video Google Assistant

https://youtu.be/nTIAUWHHJ34
