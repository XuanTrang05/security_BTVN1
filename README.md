# security_BTVN1
### CAESAR CIPHER ( MÃ CAESAR)
## Tên gọi
- Caesar cipher (mã của Julius Caesar) — dịch ký tự theo một dịch chuyển cố định.
## Thuật toán mã hoá / giải mã
- Key: k (số nguyên, 0..25)
- Mã hoá: C = (P + k) mod 26
- Giải mã: P = (C − k mod 26) (P, C = chỉ số 0..25 của chữ A..Z)
## Không gian khóa
26 (thực tế 25 khác nhau nếu xem k=0 là khóa "không dịch").
## Cách phá (không cần khóa)
Brute force: thử tất cả 26 dịch chuyển.
Nếu văn bản dài: tấn công tần suất (frequency analysis) — so sánh tần suất chữ trong bản mã với phân bố tiếng Anh.
## C++
<img width="1919" height="1079" alt="image" src="https://github.com/user-attachments/assets/585be5d7-be73-470a-82e3-540ffcaca2d4" />
## HTML
<img width="1919" height="1079" alt="image" src="https://github.com/user-attachments/assets/67441b5e-fbf6-42d2-a6f7-12b518bc3a8c" />
## AFFINE CIPHER
# Tên gọi
- Affine cipher — hàm affine trên modulo 26: E(x) = (a*x + b) mod 26
# Thuật toán mã hoá / giải mã
- Khóa: (a, b) với 0 ≤ b ≤ 25, 0 ≤ a ≤ 25 và gcd(a,26)=1 (a phải nghịch đảo modulo 26)
- Mã hoá: C = (a*P + b) mod 26
- Giải mã: P = a^{-1} * (C − b) mod 26, trong đó a^{-1} là nghịch đảo của a modulo 26
## Không gian khóa
- Số a khả dĩ là φ(26)=12 (các a nguyên tố với 26); b có 26 giá trị → 12 * 26 = 312 khóa.
- Cách phá (không cần khóa)
- Brute force trên 312 khóa — nhanh.
- Nếu văn bản dài: phân tích tần suất, đoán ánh xạ của hai chữ thường gặp (E,T) → suy ra a,b.
# C++

#
#
#
#
## HOÁN VỊ - PERMUTATION/ COLUMNAR TRANSPOSTION ( MÃ HÓA VỊ CỘT)
- Columnar Transposition (một dạng hoán vị phổ biến: sắp xếp theo key cột), và một dạng đơn giản là hoán vị vị trí cố định.
# Tên gọi
- Columnar Transposition (mã hoán vị cột)
# Thuật toán mã hoá / giải mã (columnar)
- Key: từ khoá ký tự (ex: "SECRET"), ta gán thứ tự số dựa trên thứ tự chữ: S(5) E(2) C(1) R(4) E(3) T(6) — nếu trùng chữ xử lý thứ tự từ trái.
# Mã hoá:
- Viết plaintext theo hàng vào ma trận có số cột = length(key). Nếu thiếu thì padding (ví dụ 'X').
- Đọc cột theo thứ tự index tăng dần (theo thứ tự chữ của key). Nối các cột → ciphertext.
## Giải mã:
- Biết số hàng = ceil(len(cipher)/cols). Tạo ma trận rỗng, biết thứ tự cột nên cắt ciphertext theo độ dài từng cột rồi điền xuống từng cột theo thứ tự sắp xếp rồi đọc theo hàng.
## Không gian khóa
- Số hoán vị của n ký tự = n! (n = độ dài key). Nhưng vì key thường là một từ, không gian thực dụng < n!.
## Cách phá (không cần khóa)
- Nếu biết plaintext bao gồm từ ngữ tự nhiên, dùng phân tích cấu trúc: tìm số cột hợp lý (thử nhiều n) và kiểm tra độ giống tiếng (dictionary scoring).
- Kết hợp brute force trên hoán vị nhỏ; hoặc sử dụng tần suất bigram/trigram để đánh giá khả năng plaintext.

#
#
#
#
#
#
## VIGENÈRE CIPHER
# Tên gọi
- Vigenère cipher — một cipher dạng polyalphabetic, dùng key chữ để thay đổi dịch chuyển theo từng vị trí.
# Thuật toán mã hoá / giải mã
- Key: chuỗi ký tự K (length m)
- Với plaintext P[i], key ký tự K[i mod m] tương ứng k_i = index(K[i]) (0..25)
- Mã hoá: C[i] = (P[i] + k_i) mod 26
- Giải mã: P[i] = (C[i] − k_i) mod 26
## Không gian khóa
- Nếu key độ dài ≤ L và mỗi vị trí 26 khả năng → rất lớn; nhưng thực tế key là từ nên không gian hẹp hơn.
## Cách phá (không cần khóa)
- Kasiski examination (tìm khoảng cách giữa các chuỗi lặp trong ciphertext để đo chiều dài key).
- Friedman test (đánh giá chỉ số trùng lặp để ước lượng key length).
- Sau khi biết key length m, tách ciphertext thành m chuỗi và dùng frequency analysis trên mỗi chuỗi (vì mỗi chuỗi thực chất là Caesar cipher). Sau đó thu được key.
#
#
#
#
#
#
#
#
## PLAYFAIR CIPHER
## Tên gọi
- Playfair cipher (sử dụng bảng 5×5) — mã hoá theo cặp chữ (digraphs).
## Luật chính / Chuẩn bị
- Tạo bảng 5×5 từ key phrase: viết các chữ cái của key theo thứ tự, bỏ chữ trùng; sau đó ghi các chữ cái còn lại (I/J chung nếu dùng 25 ô).
- Chia plaintext thành digraphs (cặp):
- Chỉ dùng chữ cái (A..Z), hợp nhất I/J.
- Nếu hai ký tự trong 1 cặp giống nhau thì chèn ký tự pad (thường 'X') giữa chúng và tiếp tục.
- Nếu cuối cùng còn 1 ký tự lẻ thì thêm 'X' để lấp.
* Mã hoá theo các luật:
- Nếu hai chữ nằm cùng hàng: thay mỗi chữ bằng chữ bên phải nó (vòng).
- Nếu cùng cột: thay bằng chữ phía dưới nó.
- Nếu tạo thành hình chữ nhật: mỗi chữ thay bằng chữ cùng hàng nhưng ở cột của chữ kia (nằm cùng hàng với mình, cột lấy của chữ kia).
*Giải mã: tương tự nhưng chuyển trái / lên thay vì phải / xuống.
## Không gian khóa
- Keyspace tương ứng với mọi chuỗi sắp xếp chữ => khoảng 25! (rất lớn), nhưng thực tế key phrases giới hạn.
## Cách phá (không cần khóa)
- Tấn công thống kê digraphs (bigrams) — Playfair phá cấu trúc tần suất digraphs, dùng thuật toán tối ưu (simulated annealing, hill-climbing) + scoring (log-likelihood dựa trên ngữ liệu).
- Với ciphertext dài, các kỹ thuật heuristic có thể phục hồi bảng.
