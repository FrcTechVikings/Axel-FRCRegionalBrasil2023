

#pragma once

#include <frc/Joystick.h>
#include "Constants.h"

class CommandGroup {

    public:

        // Declaração dos joysticks
        frc::Joystick pilotStick {0};
        frc::Joystick operatorStick {1};

        void InitAutoCommands(); // Inicialização do autônomo do robô
        void OneCargoAuto(double delaySeconds, double dist, double tarmacExitDist); // Método autônomo de pontuar uma cargo
        void ExitTarmacAuto(double delaySeconds); // Metódo autônomo de apenas sair do tarmac

        void InitCommands(); // Inicialização dos comandos teleoperados do robô
        void PeriodicCommands(); // Comandos periódicos do teleoperado
        void PilotCommands(); // Verificação dos botões do Joystick do piloto
        void OperatorCommands(); // Verificação dos botões do Joystick do operador
        void Log(); // Registro Geral do robô

    private:

        bool safeLock = 1;

};