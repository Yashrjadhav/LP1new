import java.util.*;
public class opt {
    
    public static void main(String[] args) {
        Scanner myinp = new Scanner(System.in);
        int references, frames, hit=0, fault_count=0, page_get, cap=0, repeat=0;
        
        System.out.print("Number of Frames: ");
        frames = myinp.nextInt();

        System.out.print("Number of Reference: ");
        references = myinp.nextInt();
        int reference_string[] = new int [references];
        int page[] = new int[references];
        int opt[] = new int[references];

        for (int i = 0; i < references; i++) {
            System.out.print("Reference String "+i+": ");
            reference_string[i] = myinp.nextInt();
        }

        System.out.print("\n===============================");

        for (int i = 0; i < frames; i++) {
            page[i] = 9999;
        }

        for (int i = 0; i < references; i++) {
            System.out.println();

            hit = 0;
            for (int j = 0; j < frames; j++) {
                if (page[j] == reference_string[i]) {
                    hit = 1;
                    break;
                }
            }

            if (hit == 0) {
                for (int j = 0; j < frames; j++) {
                    page_get = page[j];
                    for (int j2 = i; j2 < references; j2++) {
                        if (page_get == reference_string[j2]) {
                            opt[j] = j2;
                            cap = 1;
                            break;
                        } else {
                            cap = 0;
                        }
                    }
                    if (cap == 0) {
                        opt[j] = 9999;
                    }
                }

                int maximum = -9999;

                for (int j = 0; j < frames; j++) {
                    if (opt[j] > maximum) {
                        maximum = opt[j];
                        repeat = j;
                    }
                }
                page[repeat] = reference_string[i];
                fault_count++;

                for (int j = 0; j < frames; j++) {
                    if (page[j] != 9999) {
                        System.out.print(page[j]+"\t");
                    }
                }
            } else {
                for (int j = 0; j < frames; j++) {
                    System.out.print("-\t");
                }
            }
        }
        System.out.print("\n===============================");
        System.out.println("\nFault: "+fault_count);
    }
}
