#define GPIO_OFFSET(x)  (x<4?((0x40004000)+((x)*0x1000)):((0x40024000)+((x-4)*0x1000)))

#define GPIO_DATA_REG(x)      (*(volatile uint32_t *)(GPIO_OFFSET(x) + (0x3FC)))
#define GPIO_DIR_REG(x)       (*(volatile uint32_t *)(GPIO_OFFSET(x) + (0x0400)))
#define GPIO_IS_REG(x)        (*((volatile uint32_t *)(GPIO_OFFSET(x) + 0x0404)))
#define GPIO_IBE_REG(x)       (*((volatile uint32_t *)(GPIO_OFFSET(x) + 0x0408)))
#define GPIO_IEV_REG(x)       (*((volatile uint32_t *)(GPIO_OFFSET(x) + 0x040C)))
#define GPIO_IM_REG(x)        (*((volatile uint32_t *)(GPIO_OFFSET(x) + 0x0410)))
#define GPIO_RIS_REG(x)       (*((volatile uint32_t *)(GPIO_OFFSET(x) + 0x0414)))
#define GPIO_MIS_REG(x)       (*((volatile uint32_t *)(GPIO_OFFSET(x) + 0x0418)))
#define GPIO_ICR_REG(x)       (*((volatile uint32_t *)(GPIO_OFFSET(x) + 0x041C)))
#define GPIO_AFSEL_REG(x)     (*((volatile uint32_t *)(GPIO_OFFSET(x) + 0x0420)))
#define GPIO_DR2R_REG(x)      (*((volatile uint32_t *)(GPIO_OFFSET(x) + 0x0500)))
#define GPIO_DR4R_REG(x)      (*((volatile uint32_t *)(GPIO_OFFSET(x) + 0x0504)))
#define GPIO_DR8R_REG(x)      (*((volatile uint32_t *)(GPIO_OFFSET(x) + 0x0508)))
#define GPIO_ODR_REG(x)       (*((volatile uint32_t *)(GPIO_OFFSET(x) + 0x050C)))
#define GPIO_PUR_REG(x)       (*((volatile uint32_t *)(GPIO_OFFSET(x) + 0x0510)))
#define GPIO_PDR_REG(x)       (*((volatile uint32_t *)(GPIO_OFFSET(x) + 0x0514)))
#define GPIO_SLR_REG(x)       (*((volatile uint32_t *)(GPIO_OFFSET(x) + 0x0518)))
#define GPIO_DEN_REG(x)       (*((volatile uint32_t *)(GPIO_OFFSET(x) + 0x051C)))
#define GPIO_LOCK_REG(x)      (*((volatile uint32_t *)(GPIO_OFFSET(x) + 0x0520)))
#define GPIO_CR_REG(x)        (*((volatile uint32_t *)(GPIO_OFFSET(x) + 0x0524)))
#define GPIO_AMSEL_REG(x)     (*((volatile uint32_t *)(GPIO_OFFSET(x) + 0x0528)))
#define GPIO_PCTL_REG(x)      (*((volatile uint32_t *)(GPIO_OFFSET(x) + 0x052C)))
#define GPIO_ADCCTL_REG(x)    (*((volatile uint32_t *)(GPIO_OFFSET(x) + 0x0530)))
#define GPIO_DMACTL_REG(x)    (*((volatile uint32_t *)(GPIO_OFFSET(x) + 0x0534)))
#define GPIO_PERIPHID4_REG(x) (*((volatile uint32_t *)(GPIO_OFFSET(x) + 0x0FD0)))
#define GPIO_PERIPHID5_REG(x) (*((volatile uint32_t *)(GPIO_OFFSET(x) + 0x0FD4)))
#define GPIO_PERIPHID6_REG(x) (*((volatile uint32_t *)(GPIO_OFFSET(x) + 0x0FD8)))
#define GPIO_PERIPHID7_REG(x) (*((volatile uint32_t *)(GPIO_OFFSET(x) + 0x0FDC)))
#define GPIO_PERIPHID0_REG(x) (*((volatile uint32_t *)(GPIO_OFFSET(x) + 0x0FE0)))
#define GPIO_PERIPHID1_REG(x) (*((volatile uint32_t *)(GPIO_OFFSET(x) + 0x0FE4)))
#define GPIO_PERIPHID2_REG(x) (*((volatile uint32_t *)(GPIO_OFFSET(x) + 0x0FE8)))
#define GPIO_PERIPHID3_REG(x) (*((volatile uint32_t *)(GPIO_OFFSET(x) + 0x0FEC)))
#define GPIO_PCELLID0_REG(x)  (*((volatile uint32_t *)(GPIO_OFFSET(x) + 0x0FF0)))
#define GPIO_PCELLID1_REG(x)  (*((volatile uint32_t *)(GPIO_OFFSET(x) + 0x0FF4)))
#define GPIO_PCELLID2_REG(x)  (*((volatile uint32_t *)(GPIO_OFFSET(x) + 0x0FF8)))
#define GPIO_PCELLID3_REG(x)  (*((volatile uint32_t *)(GPIO_OFFSET(x) + 0x0FFC)))
#define RCGCGPIO               (*(volatile uint32_t*)(0x400FE608))
	