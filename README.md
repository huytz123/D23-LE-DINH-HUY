# BAO CAO THU VIEN GPIO

## Phần I: Configure GPIO
1, Configure Led
 + void GPIO_configure_led_don(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin);
    - Bật xung clock cho cổng GPIO
    - Cấu hình chân GPIO ở chế độ Output Push-Pull
    - Sử dụng cho LED đơn hoặc LED mảng

 + void GPIO_configure_8led(GPIO_TypeDef*GPIOx,uint16_t mode);
    - Cấu hình 8 chân GPIO liên tiếp làm ngõ ra
    - mode = 0: cấu hình 8 LED ở thanh ghi CRL
    - mode = 1: cấu hình 8 LED ở thanh ghi CRH

2, Configure Button
 + void Configure_Button(GPIO_TypeDef*GPIOx, uint16_t GPIO_Pin);    
    - Bật xung clock cho cổng GPIO chứa nút nhấn
    - Cấu hình chân GPIO ở chế độ Input Pull-down
    - Thiết lập trạng thái ban đầu của nút nhấn là mức logic 0

 ## Phần II: Chức năng
 1, Điều khiển Led
  a, Điều khiển Led đơn
   + void GPIO_LED_On(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin);
   + void GPIO_LED_Off(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin);
   + void GPIO_LED_Toggle(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin);

     - Bật LED bằng cách đưa chân GPIO về mức thấp
     - Tắt LED bằng cách đưa chân GPIO lên mức cao
     - Đảo trạng thái LED kèm theo hàm trễ
  b, Điều khiển 8 Led
   + Blink_8_led() : tạo hiệu ứng sáng dần từng LED  

 2, Dùng BUTTON để bật/tắt Led
   + void Turn_on_turm_off_led (GPIO_TypeDef*GPIOBUTTONx,uint16_t BUTTON_PIN,GPIO_TypeDef*GPIOLEDx,uint16_t LED_Pin)
      GPIOBUTTONx	Cổng GPIO chứa nút nhấn (VD: GPIOA)
      BUTTON_PIN	Chân GPIO của nút nhấn (VD: PA0)
      GPIOLEDx	    Cổng GPIO điều khiển LED (VD: GPIOC)
      LED_Pin	    Chân GPIO của LED (VD: PC13)

   + Mục đích của hàm:
        Hàm Turn_on_turm_off_led() được sử dụng để điều khiển LED theo cơ chế mỗi lần nhấn nút thì LED đổi trạng thái (Toggle). Cách xử lý này giúp LED không bị nhấp nháy khi giữ nút nhấn.

        Giải thích chi tiết:

            - prev_state dùng để lưu trạng thái nút nhấn ở lần đọc trước, phục vụ cho việc phát hiện cạnh lên (0 → 1).
            - led_state lưu trạng thái logic hiện tại của LED (0: tắt, 1: bật).
            - Thanh ghi IDR (Input Data Register) được dùng để đọc trạng thái chân nút nhấn.
            - Điều kiện prev_state == 0 && buttonstate == 1 giúp phát hiện đúng thời điểm nút vừa được nhấn.
            - Khi phát hiện nhấn mới, trạng thái LED được đảo bằng toán tử !.
            - Thanh ghi ODR (Output Data Register) được sử dụng để điều khiển mức logic xuất ra chân LED.
            - Sau khi xử lý, trạng thái nút nhấn hiện tại được gán lại cho prev_state để chuẩn bị cho lần kiểm tra tiếp theo.
          





