# Monitor de Temperatura e Umidade com ESP32 e DHT11

Este repositório contém o desenvolvimento de um sistema de monitoramento ambiental utilizando o microcontrolador **ESP32** e o sensor **DHT11**. O projeto integra hardware real, simulação digital e práticas de documentação de software.

## 🚀 Funcionalidades

*   **Leitura de Sensores**: Coleta em tempo real de dados de temperatura e umidade via sensor DHT11.
*   **Sinalização Visual**: Uso de LEDs para indicação de status e alertas baseados em lógica de programação.
*   **Prototipagem Híbrida**: Desenvolvimento validado tanto em bancada física quanto em simulador online.
*   **Código Documentado**: Firmware escrito em C++ com foco em legibilidade e manutenção.

## 🛠️ Tecnologias e Componentes

*   **Microcontrolador**: ESP32.
*   **Sensor**: DHT11.
*   **Linguagem**: C++ (Arduino Framework).
*   **IDE**: VS Code + PlatformIO.
*   **Simulador**: Wokwi.

## 📁 Estrutura do Repositório

O projeto foi estruturado para permitir a escalabilidade e futura integração com ecossistemas de dados:

*   **`/dht11`**: Contém o código-fonte do firmware (projeto PlatformIO).
*   **`/scripts_python` (Em breve)**: Pasta reservada para a integração com scripts Python para persistência em Banco de Dados e dashboards.

## 💻 Simulação Interativa

Você pode testar a lógica do sistema sem necessidade de hardware físico:

👉 [Simulação no Wokwi](https://wokwi.com/projects/462638599631774721)

> **Nota Técnica**: Na simulação via Wokwi, foi utilizado o modelo **DHT22** devido à disponibilidade nativa no simulador. O código foi devidamente adaptado para manter a compatibilidade com o **DHT11** utilizado na montagem física.

## 📸 Demonstração do Projeto

![Protótipo Real](https://media.licdn.com/dms/image/v2/D4E22AQF5eJK-8YBp_A/feedshare-shrink_800/B4EZ3qTVFGJQAg-/0/1777752429193?e=1779321600&v=beta&t=25wbFet4rTfUJJIKQYeav5ewdAo79bvvvmQhv07tfUk)

---
**Desenvolvido por Pablo Pereira** 🚀
[Linkedin](www.linkedin.com/in/pablopereira70)