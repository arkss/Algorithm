import math


class Car:
    def __init__(self, car_number):
        self.car_number = car_number
        self.io_queue = []
        self.parking_time = 0
        self.fee = 0

    def update_fee(self, base_fee, base_time, unit_time, unit_fee):
        if self.parking_time <= base_time:
            self.fee = base_fee
        else:
            self.fee = (
                base_fee
                + int(math.ceil(float(self.parking_time - base_time) / unit_time))
                * unit_fee
            )


def hour_to_minute(hour):
    return int(hour[:2]) * 60 + int(hour[3:])


def solution(fees, records):
    base_time, base_fee, unit_time, unit_fee = fees

    car_dict = {}

    for record in records:
        hm_time, car_number, io = record.split()
        minute = hour_to_minute(hm_time)

        if car_number not in car_dict:
            car_dict[car_number] = Car(car_number)

        car = car_dict[car_number]

        if io == "IN":
            car.io_queue.append(minute)
        elif io == "OUT":
            car.parking_time += minute - car.io_queue.pop(0)

    for car in car_dict.values():
        if car.io_queue:
            car.parking_time += hour_to_minute("23:59") - car.io_queue.pop(0)
        car.update_fee(base_fee, base_time, unit_time, unit_fee)

    sorted_cars = sorted(car_dict.values(), key=lambda x: x.car_number)
    answer = [car.fee for car in sorted_cars]

    return answer


fees = [180, 5000, 10, 600]
records = [
    "05:34 5961 IN",
    "06:00 0000 IN",
    "06:34 0000 OUT",
    "07:59 5961 OUT",
    "07:59 0148 IN",
    "18:59 0000 IN",
    "19:09 0148 OUT",
    "22:59 5961 IN",
    "23:00 5961 OUT",
]
result = [14600, 34400, 5000]

print(solution(fees, records))
