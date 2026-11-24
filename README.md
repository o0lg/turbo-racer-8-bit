# 🏎️ TURBO RACER 8-BIT

## Project Pengenalan Pemrograman Kelompok 12

**Turbo Racer 8-Bit** adalah game balapan sederhana berbasis terminal yang dibuat menggunakan bahasa pemrograman C++ dengan library NCurses. Pemain harus menghindari mobil musuh yang datang dari arah atas dengan menggerakkan mobil ke kiri dan kanan.

Proyek ini dibuat sebagai bentuk penerapan materi dasar pemrograman C++ dalam mata kuliah Pengenalan Pemrograman.

---

## Anggota Kelompok

| No. | Nama Lengkap |
|:---:|---|
| 1 | Ahmad Rizky Saputra |
| 2 | Safira Ramadhani I |
| 3 | M. Arfa Rabbani Algusma |

**Kelas:** B  
**Kelompok:** 12  
**Mata Kuliah:** Pengenalan Pemrograman

---

## Fitur Game

1. **Kontrol Mobil:** Pemain dapat menggerakkan mobil ke kiri dan kanan.
2. **Mobil Musuh:** Terdapat lima slot mobil musuh yang muncul secara acak.
3. **Sistem Nyawa:** Pemain memiliki tiga nyawa. Nyawa berkurang setiap kali terjadi tabrakan.
4. **Sistem Skor:** Skor bertambah ketika mobil musuh berhasil dilewati.
5. **Sistem Rekor:** Rekor tertinggi disimpan ke dalam file `skor.txt`.
6. **Tingkat Kesulitan:** Kecepatan permainan meningkat seiring bertambahnya skor.
7. **Game Over:** Permainan berakhir ketika nyawa pemain habis.

---

## Kontrol Permainan

| Tombol | Fungsi |
|:---:|---|
| ← | Menggerakkan mobil ke kiri |
| → | Menggerakkan mobil ke kanan |
| Q | Keluar dari permainan |

---

## Teknologi yang Digunakan

- **Bahasa Pemrograman:** C++
- **Library:** NCurses
- **File Handling:** `fstream`
- **Random Number:** `cstdlib`
- **Time:** `ctime`

---

## Penerapan Materi Pengenalan Pemrograman

Dalam proyek ini terdapat beberapa konsep dasar pemrograman yang diterapkan:

| Materi | Penerapan |
|---|---|
| Variabel | Menyimpan posisi mobil, skor, nyawa, dan frame |
| Array | Menyimpan posisi lima mobil musuh |
| Percabangan | Mengatur kontrol pemain dan kondisi tabrakan |
| Perulangan | Memproses pergerakan musuh dan jalannya permainan |
| Function Library | Menggunakan fungsi dari library NCurses |
| Random Number | Mengatur kemunculan mobil musuh secara acak |
| File Handling | Membaca dan menyimpan rekor permainan |
| Operator | Melakukan perhitungan skor, posisi, dan kecepatan |

---

## Cara Menjalankan Program

### 1. Persiapan

Pastikan komputer sudah memiliki:

- Compiler G++.
- Library NCurses.
- Terminal Linux atau lingkungan yang mendukung NCurses.

### 2. Instalasi NCurses

Untuk Ubuntu/Debian, jalankan perintah:

```bash
sudo apt update
sudo apt install libncurses-dev g++
```

### 3. Clone Repository

```bash
git clone https://github.com/USERNAME/REPOSITORY.git
```

Masuk ke folder proyek:

```bash
cd REPOSITORY
```

### 4. Compile Program

```bash
g++ balap_ncurses.cpp -lncurses -o balap
```

### 5. Jalankan Game

```bash
./balap
```

---

## Struktur File

```text
TURBO-RACER-8-BIT/
│
├── balap_ncurses.cpp
├── skor.txt
└── README.md
```

**Keterangan:**

- `balap_ncurses.cpp` merupakan file utama yang berisi kode program game.
- `skor.txt` digunakan untuk menyimpan rekor tertinggi pemain.
- `README.md` berisi dokumentasi proyek.

File `skor.txt` akan dibuat atau diperbarui secara otomatis ketika pemain mendapatkan rekor baru.

---

## Tujuan Pembuatan

Tujuan pembuatan proyek Turbo Racer 8-Bit adalah untuk memahami dan menerapkan konsep dasar pemrograman C++ melalui sebuah permainan sederhana.

Melalui proyek ini, anggota kelompok dapat mempelajari penggunaan variabel, array, percabangan, perulangan, pengolahan file, serta penggunaan library eksternal NCurses untuk membuat antarmuka permainan berbasis terminal.

---

## Penutup

Turbo Racer 8-Bit merupakan proyek sederhana yang menggabungkan konsep dasar pemrograman dengan permainan interaktif. Diharapkan proyek ini dapat menjadi sarana pembelajaran dan meningkatkan pemahaman anggota kelompok dalam mengembangkan program menggunakan bahasa C++.

**Dibuat oleh Kelompok 12, Kelas B**  
**Mata Kuliah Pengenalan Pemrograman**
