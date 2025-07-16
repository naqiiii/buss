#include <stdio.h>
#include <stdlib.h>

#define TOTAL_SEATS 44
#define WINDOW_SEATS 22

int main() {
    int Bseat[TOTAL_SEATS];     // Seat status array: 0 = booked, 1 = available
    int Wseat[WINDOW_SEATS] = {1, 4, 5, 8, 9, 12, 13, 16, 17, 20, 21, 24, 25, 28, 29, 32, 33, 36, 37, 40, 41, 44};

    // Ticket prices
    int Aticket = 44;  // Adult
    int Sticket = 33;  // Senior
    int Cticket = 28;  // Child
    int Bticket = 0;   // Baby
    int baggage_limit = 25;
    int baggage_charge = 4;

    // Initialize all seats to available (1)
    for (int i = 0; i < TOTAL_SEATS; i++) {
        Bseat[i] = 1;
    }

    printf("=====================================================\n");
    printf("   Welcome to SAPTCO Bus Service (Makkah to Madinah)\n");
    printf("=====================================================\n\n");

    char more = 'y';
    int total_fare = 0;
    int passenger_count = 0;

    while (more == 'y' || more == 'Y') {
        // Show available seats
        printf("\nAvailable Seats:\n");
        for (int i = 0; i < TOTAL_SEATS; i++) {
            if (Bseat[i] == 1)
                printf("%02d ", i + 1);
            else
                printf("-- ");
            if ((i + 1) % 11 == 0) printf("\n");
        }

        // Ask for seat number
        int seat_num;
        printf("\nEnter seat number you want to book (1-44): ");
        scanf("%d", &seat_num);

        // Validate seat number
        if (seat_num < 1 || seat_num > 44 || Bseat[seat_num - 1] == 0) {
            printf("Invalid or already booked seat. Please try again.\n");
            continue;
        }

        // Mark seat as booked
        Bseat[seat_num - 1] = 0;

        // Get passenger age
        int age, baggage, fare = 0;
        printf("Enter passenger's age: ");
        scanf("%d", &age);

        // Category and base fare
        if (age < 2) {
            printf("Passenger is a Baby (Free Ticket).\n");
            fare = Bticket;
        } else if (age >= 2 && age <= 6) {
            printf("Passenger is a Child. Ticket = %d SAR\n", Cticket);
            fare = Cticket;
        } else if (age >= 65) {
            printf("Passenger is a Senior Citizen. Ticket = %d SAR\n", Sticket);
            fare = Sticket;
        } else {
            printf("Passenger is an Adult. Ticket = %d SAR\n", Aticket);
            fare = Aticket;
        }

        // Baggage info
        printf("Enter baggage weight in kg: ");
        scanf("%d", &baggage);
        if (baggage > baggage_limit) {
            printf("Extra baggage charges applied: +%d SAR\n", baggage_charge);
            fare += baggage_charge;
        }

        passenger_count++;
        total_fare += fare;

        printf("Passenger %d booked seat %d. Total Fare = %d SAR\n", passenger_count, seat_num, fare);

        printf("\nDo you want to book another seat? (y/n): ");
        scanf(" %c", &more);
    }

    // Final summary
    printf("\n===================================\n");
    printf("Total Passengers: %d\n", passenger_count);
    printf("Total Fare: %d SAR\n", total_fare);
    printf("===================================\n");
    printf("Thank you for traveling with SAPTCO!\n");

    return 0;
}
